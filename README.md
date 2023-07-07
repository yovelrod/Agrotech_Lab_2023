# Agrotech_Lab_2023 project:
The purpose of my project was to build a meteorological station to measure climate data such as wind speed, temperature, and humidity in my residential area. To achieve this goal, I utilized various sensors, including a wind sensor for measuring wind speed and direction, a temperature sensor, a humidity sensor, and a barometric pressure sensor. Additionally, to ensure the station's placement in a representative location with minimal environmental disturbances, I had to position it far away from a power source. Therefore, I incorporated a battery that could be charged using a solar panel.

# Hardware and assembly:
![7c742051-36e1-453e-a3e2-02cff936ee7f](https://github.com/yovelrod/Agrotech_Lab_2023/assets/118877588/83ec2dd8-f0cc-48bb-bac8-e0c2dbe8a08b)

![WhatsApp Image 2023-07-03 at 19 51 27](https://github.com/yovelrod/Agrotech_Lab_2023/assets/118877588/999d50e0-556c-48cc-9044-1e2b07673b07)


<img width="797" alt="image" src="https://github.com/yovelrod/Agrotech_Lab_2023/assets/118877588/ce5d22b4-bbcf-4bf4-83ca-90207b1f9ad6">


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

| ID | Part name                          | Part number                        | Quantity |
|----|------------------------------------|------------------------------------|----------|
|    | [ESP32 Board](https://www.aliexpress.com/item/1005003145192016.html?spm=a2g0o.order_list.order_list_main.116.32271802WzfUcm)       |                                    | 1        |
|    | [ADS1115 ADC Module](https://www.aliexpress.com/item/32817162654.html?spm=a2g0o.order_list.order_list_main.168.32271802WzfUcm)|                                  | 1        |
|    | [3.3V to 5V Logic Level Converter](https://www.aliexpress.com/item/4000552920569.html?spm=a2g0o.order_list.order_list_main.245.32271802WzfUcm) |             | 1        |
|    | [BME280 Sensor](https://www.aliexpress.com/item/32862445164.html?spm=a2g0o.order_list.order_list_main.141.32271802WzfUcm)     |                                    | 1        |
|    | [SHT31 Sensor](https://www.aliexpress.com/item/1005004088598291.html?spm=a2g0o.order_list.order_list_main.240.32271802WzfUcm)       |                                    | 1        |
|    | [Wind Speed Sensor](https://www.aliexpress.com/item/1005004770322638.html?spm=a2g0o.order_list.order_list_main.65.32271802WzfUcm) |                                | 1        |
|    | [Wind Direction Sensor](https://www.aliexpress.com/item/1005004770322638.html?spm=a2g0o.order_list.order_list_main.65.32271802WzfUcm) |                          | 1        |
|    | [12V to 3.3V Step-Down Converter](https://www.aliexpress.com/item/32949929824.html?spm=a2g0o.order_list.order_list_main.204.32271802WzfUcm&gatewayAdapt=glo2isr) |            | 1        |
|    | [12V to 5V Step-Down Converter](https://www.aliexpress.com/item/32949929824.html?spm=a2g0o.order_list.order_list_main.204.32271802WzfUcm&gatewayAdapt=glo2isr) |                | 1        |

