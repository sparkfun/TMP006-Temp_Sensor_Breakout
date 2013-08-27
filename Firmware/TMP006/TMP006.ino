// An example to get started with the TMP006 temperature sensor
//Modified from the Adafruit library code
//Original Code license:
///***************************************************
 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, all text above must be included in any redistribution
****************************************************/

// Only things needed to configure are the sensor address and
// samples per reading, however the defaults work fine if using
// just one TMP006 sensor. Check out the hook up guide tutorial
// if you want a better explanation of the hardware and code.

#include <stdint.h>
#include <math.h>
#include <Wire.h>
#include "I2C_16.h"
#include "TMP006.h"

uint8_t sensor1 = 0x40; // I2C address of TMP006, can be 0x40-0x47
uint16_t samples = TMP006_CFG_8SAMPLE; // # of samples per reading, can be 1/2/4/8/16

void setup()
{
  Serial.begin(9600);
  Serial.println("TMP006 Example");

  config_TMP006(sensor1, samples);
}

void loop()
{
  float object_temp = readObjTempC(sensor1);
  Serial.print("Object Temperature: "); 
  Serial.print(object_temp); Serial.println("*C");

  float sensor_temp = readDieTempC(sensor1);
  Serial.print("Sensor Temperature: "); 
  Serial.print(sensor_temp); Serial.println("*C");

  delay(2000); // delay 1 second for every 4 samples per reading
}
