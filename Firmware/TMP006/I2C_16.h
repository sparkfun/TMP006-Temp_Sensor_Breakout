// Read 16 bit int from I2C address addr and register reg
uint16_t read16(uint8_t addr, uint8_t reg);

// Write data to I2C address addr, register reg
void write16(uint8_t addr, uint8_t reg, uint16_t data);
