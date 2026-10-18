#include <WiFi.h>

const char* targetSSID = "Network Name"; //settings 

const int HIGH_THRESHOLD   = -67; 	
const int MEDIUM_THRESHOLD = -75;    
const int LOW_THRESHOLD    = -83;	

const unsigned long scanInterval = 1500; //

const int GREEN_LED  = 2; //Pin Configuration
const int YELLOW_LED = 3;
const int RED_LED    = 4;

const int RESET_BUTTON = 5;

void checkTargetWiFi() { 	//Wifi check function
  Serial.println();
  Serial.println("=====================");
  Serial.print("Checking: ");
  Serial.println(targetSSID);

  int networkCount = WiFi.scanNetworks();

  int targetRSSI = -999;
  bool found = false;

  for (int i=0; i<networkCount; i++) {         //Look for the target network
    if (WiFi.SSID(i) == targetSSID) {
      targetRSSI = WiFi.RSSI(i);
      found = true;
      break;
    }
  }

  digitalWrite(GREEN_LED, LOW);            // Turn all LEDs off before displaying new result
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if (!found) {    				 //display result
    Serial.println("RSSI: ZERO");
    Serial.println("Network not detected");
    digitalWrite(RED_LED, HIGH); 
  } else {
    Serial.print("RSSI: ");
    Serial.print(targetRSSI);
    Serial.println(" dBm");

    if (targetRSSI >= HIGH_THRESHOLD) {
      Serial.println("Signal: HIGH");
      digitalWrite(GREEN_LED, HIGH);
    } else if (targetRSSI >= MEDIUM_THRESHOLD) {
      Serial.println("Signal: MEDIUM");
      digitalWrite(YELLOW_LED, HIGH);
    } else if (targetRSSI >= LOW_THRESHOLD) {
      Serial.println("Signal: LOW");
      digitalWrite(RED_LED, HIGH);
    } else {
      Serial.println("Signal: ZERO");
      digitalWrite(RED_LED, HIGH);
    }
  }
  WiFi.scanDelete();
}

void setup() {    					//setup
  Serial.begin(115200);
  delay(1000);

  pinMode(GREEN_LED, OUTPUT);   //Configure LEDs
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(RESET_BUTTON, INPUT_PULLUP);   // Configure reset button

  digitalWrite(GREEN_LED, LOW);   // Turn LEDs off initially
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  WiFi.mode(WIFI_STA);  //start wifi
  WiFi.disconnect();

  delay(100);

  Serial.println("ESP32-C3 WiFi Signal Monitor");
  Serial.print("Target: ");
  Serial.println(targetSSID);

  checkTargetWiFi();
}

void loop() {   //main 
  if (digitalRead(RESET_BUTTON) == LOW) {     
    Serial.println("Reset button pressed");

    delay(100);  

    ESP.restart();
  }
  delay(scanInterval);

  checkTargetWiFi();
}
