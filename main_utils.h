#ifndef MAIN_UTILS_H
#define MAIN_UTILS_H


#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <ArduinoOTA.h>
#include "sht_utils.h"
#include "bme_utils.h"
#include "ads_utils.h"
#include "wind_utils.h"
#include "time_utils.h"

#define WIND_SPEED_SENSOR_ADC_CH 1
#define WIND_DIR_SENSOR_ADC_CH 3
#define SENSOR_READING_INTERVAL (15 * 60 * 1000) // 15 minutes in milliseconds
#define WIND_READING_INTERVAL 60*1000


// Pin Definitions
#define SDA 33
#define SCL 35
#define ONBOARD_LED 15

extern boolean sensors_flag;
extern boolean wind_speed_flag;
extern boolean wind_dir_flag;

extern unsigned long last_wind_sample_time;
extern unsigned long last_sensors_reading_time;
extern bool ads1115_error;
extern bool sht31_error;
extern bool bme280_error;

/**
 * @brief Error information structure
 */
struct ErrorInfo {
  bool ads1115; ///< ADS1115 error flag
  bool sht31;   ///< SHT31 error flag
  bool bme280;  ///< BME280 error flag
};

/**
 * @brief Read sensor data
 *
 * @param[out] temperature Temperature reading
 * @param[out] humidity Humidity reading
 * @param[out] wind_speed Wind speed reading
 * @param[out] wind_direction Wind direction reading
 */
void readSensorData(float& temperature, float& humidity,float &pressure, float& wind_speed, String& wind_direction);

/**
 * @brief Print sensor data
 *
 * @param[in] temperature Temperature reading
 * @param[in] humidity Humidity reading
 * @param[in] wind_speed Wind speed reading
 * @param[in] wind_direction Wind direction reading
 */
void printSensorData(float temperature, float humidity,float pressure, float wind_speed, const String& wind_direction);



/**
 * @brief Initialize sensors
 */
void initSensors();

/**
 * @brief Reset Arduino Cloud variables
 */
void resetArduinoCloudVariables();

/**
 * @brief Set I2C communication
 */
void setI2C();

/**
 * @brief Print error information
 *
 * @param[in] errorInfo Error information structure
 */
void printError(const ErrorInfo& errorInfo);

#endif // MAIN_UTILS_H
