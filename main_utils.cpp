#include "main_utils.h"

bool ads1115_error = false;
bool sht31_error = false;
bool bme280_error = false;
unsigned long last_sensors_reading_time = 0;
unsigned long last_wind_sample_time = 0;

bool sensors_flag = false;
bool wind_speed_flag = false;
bool wind_dir_flag = false;

/**
 * Reads sensor data from various sensors.
 * 
 * @param temperature [out] - The variable to store the temperature reading.
 * @param humidity [out] - The variable to store the humidity reading.
 * @param pressure [out] - The variable to store the pressure reading.
 * @param wind_speed [out] - The variable to store the wind speed reading.
 * @param wind_direction [out] - The variable to store the wind direction reading.
 */
void readSensorData(float& temperature, float& humidity, float& pressure, float& wind_speed, String& wind_direction) {
  if (millis() - last_sensors_reading_time >= SENSOR_READING_INTERVAL) {
    // Read temperature and humidity from SHT31 sensor
    temperature = readTemperature();
    humidity = readHumidity();
    pressure = readPressure();
    printSensorData(temperature, humidity, pressure, wind_speed, wind_direction);
    last_sensors_reading_time = millis();
    sensors_flag = true;
  }

  // Read wind speed from ADS1115 analog-to-digital converter
  int16_t wind_speed_adc_ch_reading = ads.readADC_SingleEnded(WIND_SPEED_SENSOR_ADC_CH);
  float wind_speed_volts = ads.computeVolts(wind_speed_adc_ch_reading);
  float temp_wind_speed = sampleWindSpeed(wind_speed_volts, aveWindSpdCalcArr);

  if (wind_speed_flag) {
    wind_speed = temp_wind_speed;
    wind_speed_flag = false;
  }
  
  // Read wind direction from ADS1115 analog-to-digital converter
  int16_t wind_dir_adc_ch_reading = ads.readADC_SingleEnded(WIND_DIR_SENSOR_ADC_CH);
  float wind_dir_volts = ads.computeVolts(wind_dir_adc_ch_reading);
  String temp_wind_direction = getWindDirectionString(sampleWindDirection(wind_dir_volts, aveWindDirCalcArr));

  if (wind_dir_flag) {
    wind_direction = temp_wind_direction;
    wind_dir_flag = false;
  }
}

/**
 * Prints the sensor data to the Serial monitor.
 * 
 * @param temperature - The temperature reading in degrees Celsius.
 * @param humidity - The humidity reading in percentage.
 * @param pressure - The pressure reading in hectopascals (hPa).
 * @param wind_speed - The wind speed reading in kilometers per hour (km/h).
 * @param wind_direction - The wind direction as a string.
 */
void printSensorData(float temperature, float humidity, float pressure, float wind_speed, const String& wind_direction) {
  // Print current local time
  printLocalTime();

  // Print temperature, humidity, and pressure readings
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity, 1);
  Serial.print("%, Pressure: ");
  Serial.print(pressure, 2);
  Serial.println(" hPa");

  // Print wind speed and direction readings
  Serial.print("Wind Speed: ");
  Serial.print(wind_speed);
  Serial.println(" km/h");

  Serial.print("Wind Direction: ");
  Serial.println(wind_direction);
  Serial.println("--------------------");
}

/**
 * Initializes the sensors used in the system.
 */
void initSensors() {
  // Setup ADS1115 analog-to-digital converter
  setupADS1115();

  // Setup BME280 temperature, pressure, and humidity sensor
  setupBME280();

  // Setup SHT31 temperature and humidity sensor
  setupSHT31();
}

/**
 * Resets the necessary Arduino Cloud variables.
 */
void resetArduinoCloudVariables() {
  // Reset Arduino Cloud variables
  // TODO: Add code to reset the necessary Arduino Cloud variables
}

/**
 * Sets up I2C communication using SDA and SCL pin definitions.
 */
void setI2C() {
  // Set up I2C communication using SDA and SCL pin definitions
  Wire.begin(SDA, SCL);
  Wire.setClock(100000);
}

/**
 * Prints error information.
 * 
 * @param errorInfo - The ErrorInfo struct containing error flags.
 */
void printError(const ErrorInfo& errorInfo) {
  // Print error information
  if (errorInfo.ads1115) {
    Serial.println("Error: ADS1115 component error!");
  }
  if (errorInfo.sht31) {
    Serial.println("Error: SHT31 component error!");
  }
  if (errorInfo.bme280) {
    Serial.println("Error: BME280 component error!");
  }
}
