#include "bme_utils.h"

Adafruit_BME280 bme;
float const LOCAL_ALTITUDE = 63; // Adjust this value to your local altitude

/**
 * Set up the BME280 sensor module.
 * This function initializes the BME280 sensor and checks for its presence.
 * If the sensor is not found, it sets the bme280_error flag to true.
 */
void setupBME280() {
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor. Please check the wiring!");
    bme280_error = true;
  }
}

/**
 * Read the atmospheric pressure from the BME280 sensor.
 *
 * @return The atmospheric pressure reading in hectopascals (hPa).
 */
float readPressure() {
  float localPressure = bme.readPressure(); // Pressure in hPa
  float correctedPressure = bme.seaLevelForAltitude(LOCAL_ALTITUDE, localPressure);
  return correctedPressure / 100.0; // Convert to hPa
}
