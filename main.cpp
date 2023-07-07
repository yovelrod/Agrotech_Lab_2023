#include "main_utils.h"
#include "arduino_secrets.h" //must me in the main file
#include "thingProperties.h" //must me in the main file

// Variables
unsigned long previousMillis = 0;
unsigned long previousPressureMillis = 0;
const unsigned long interval = 60UL * 1000UL;
const unsigned long pressureInterval = 60UL * 1000UL;
boolean wifiConnected = false;
ErrorInfo errorInfo;

// Blink variables
const unsigned long startupBlinkDuration = 3000;
const unsigned long blinkInterval = 500;

void setup() {
  Serial.begin(115200);
  delay(1500);

  // Initialize onboard LED pin
  pinMode(ONBOARD_LED, OUTPUT);

  // Startup blink
  unsigned long startupBlinkStartMillis = millis();
  while (millis() - startupBlinkStartMillis <= startupBlinkDuration) {
    digitalWrite(ONBOARD_LED, HIGH);
    delay(blinkInterval);
    digitalWrite(ONBOARD_LED, LOW);
    delay(blinkInterval);
  }

  // Reset cloud variables
  temp = 0;
  hum = 0;
  pressure = 0;
  wind_speed = 0;

  // Initialize IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  setI2C();
  initSensors();

  // Initialize NTP client and set up time
  setupTime();

  // Initialize error info
  errorInfo.ads1115 = ads1115_error;
  errorInfo.sht31 = sht31_error;
  errorInfo.bme280 = bme280_error;

  temp = readTemperature();
  hum = readHumidity();
  pressure = readPressure();
}

void loop() {

ArduinoCloud.update();
  if (sensors_flag || (wind_speed_flag && wind_dir_flag))
  {
    
   sensors_flag = false;
    wind_speed_flag = false;
    wind_dir_flag = false;
  }

  
  wifiConnected = ArduinoCloud.connected();

  unsigned long currentMillis = millis();

  printError(errorInfo);

  // Blink LED if WiFi is disconnected
  if (!wifiConnected) {
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      digitalWrite(ONBOARD_LED, !digitalRead(ONBOARD_LED));
    }
  } else {
    digitalWrite(ONBOARD_LED, HIGH);
  }

  // Read temperature, humidity, wind speed, and wind direction every interval

    readSensorData(temp, hum,pressure, wind_speed,wind_direction);
    previousMillis = currentMillis;

}
