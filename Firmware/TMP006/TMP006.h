//Modified by SparkFun Electronics. 
//We release this code under ([Beerware license](http://en.wikipedia.org/wiki/Beerware)).

//Original Code license:
 /***************************************************
  This is a library for the TMP006 Temp Sensor

  Designed specifically to work with the Adafruit TMP006 Breakout
  ----> https://www.adafruit.com/products/1296

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Constants for calculating object temperature
#define TMP006_B0 -0.0000294
#define TMP006_B1 -0.00000057
#define TMP006_B2 0.00000000463
#define TMP006_C2 13.4
#define TMP006_TREF 298.15
#define TMP006_A2 -0.00001678
#define TMP006_A1 0.00175
#define TMP006_S0 6.4  // * 10^-14

// Configuration Settings
#define TMP006_CFG_RESET    0x8000
#define TMP006_CFG_MODEON   0x7000
#define TMP006_CFG_1SAMPLE  0x0000
#define TMP006_CFG_2SAMPLE  0x0200
#define TMP006_CFG_4SAMPLE  0x0400
#define TMP006_CFG_8SAMPLE  0x0600
#define TMP006_CFG_16SAMPLE 0x0800
#define TMP006_CFG_DRDYEN   0x0100
#define TMP006_CFG_DRDY     0x0080

// Registers to read thermopile voltage and sensor temperature
#define TMP006_VOBJ  0x00
#define TMP006_TAMB 0x01
#define TMP006_CONFIG 0x02


// Configures sensor, use before reading from it
void config_TMP006(uint8_t addr, uint16_t samples);

// Read raw sensor temperature
int16_t readRawDieTemperature(uint8_t addr);

// Read raw thermopile voltage
int16_t readRawVoltage(uint8_t addr);

// Calculate object temperature based on raw sensor temp and thermopile voltage
double readObjTempC(uint8_t addr);

// Caculate sensor temperature based on raw reading
double readDieTempC(uint8_t addr);
