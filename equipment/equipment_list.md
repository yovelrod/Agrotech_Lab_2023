## Components and Sensors

- ESP32 Board: The ESP32 microcontroller board serves as the main controller for the weather station.

- ADS1115 ADC Module: The ADS1115 analog-to-digital converter is used to read analog signals from the wind speed and wind direction sensors.

- 3.3V to 5V Logic Level Converter: The logic level converter is used to convert the logic signals between 3.3V and 5V to ensure compatibility between the ESP32 and other components.

- BME280 Sensor: The BME280 sensor measures temperature, humidity, and atmospheric pressure.

- SHT31 Sensor: The SHT31 sensor measures temperature and humidity.

- Wind Speed Sensor: The wind speed sensor provides data on the speed of the wind. It requires a 12V input and outputs a voltage between 0V and 5V.

- Wind Direction Sensor: The wind direction sensor determines the direction of the wind. It also operates with a 12V input and outputs a voltage between 0V and 5V.

- 12V to 3.3V Step-Down Converter: This converter is used to step down the 12V input voltage to 3.3V, providing power to the ESP32, SHT31, BME280, and one side of the logic level converter.

- 12V to 5V Step-Down Converter: This converter steps down the 12V input voltage to 5V, supplying power to the other side of the logic level converter and the ADS1115 ADC module.

## Bill of Materials:

| ID | Part name                          | Part number | Quantity |
|----|------------------------------------|-------------|----------|
|    | ESP32 Board                        |             | 1        |
|    | ADS1115 ADC Module                 |             | 1        |
|    | 3.3V to 5V Logic Level Converter    |             | 1        |
|    | BME280 Sensor                      |             | 1        |
|    | SHT31 Sensor                       |             | 1        |
|    | Wind Speed Sensor                  |             | 1        |
|    | Wind Direction Sensor              |             | 1        |
|    | 12V to 3.3V Step-Down Converter     |             | 1        |
|    | 12V to 5V Step-Down Converter       |             | 1        |
|    | Other necessary electronic parts   |             | -        |



