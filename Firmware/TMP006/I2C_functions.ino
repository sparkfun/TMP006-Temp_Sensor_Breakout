// Read 16 bit int from I2C address addr and register reg
uint16_t read16(uint8_t addr, uint8_t reg) {
  uint16_t data;

  Wire.beginTransmission(addr);
  Wire.write(reg); // send register address to read from
  Wire.endTransmission();
  
  //Wire.beginTransmission(addr); //commenting out since this is redundant and used when writing data to the I2C slave. see comments here=> https://github.com/sparkfun/TMP006-Temp_Sensor_Breakout/issues/9
  Wire.requestFrom((uint8_t)addr, (uint8_t)2); // request 2 bytes of data
  data = Wire.read(); // receive data
  data <<= 8;
  data |= Wire.read();
  //Wire.endTransmission(); //commenting out since this is redundant and used when writing data to the I2C slave.

  return data;
}

// Write data to I2C address addr, register reg
void write16(uint8_t addr, uint8_t reg, uint16_t data) {
  Wire.beginTransmission(addr);
  Wire.write(reg); // sends register address to write to
  Wire.write(data>>8);  // write data
  Wire.write(data); 
  Wire.endTransmission();
}

