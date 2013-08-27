// Configures sensor, use before reading from it
void config_TMP006(uint8_t addr, uint16_t samples)
{
  Wire.begin();
  write16(addr, TMP006_CONFIG, samples | TMP006_CFG_MODEON | TMP006_CFG_DRDYEN);
}

// Read raw sensor temperature
int16_t readRawDieTemperature(uint8_t addr)
{
  int16_t raw = read16(addr, TMP006_TAMB);

  raw >>= 2;
  return raw;
}

// Read raw thermopile voltage
int16_t readRawVoltage(uint8_t addr) 
{
  int16_t raw = read16(addr, TMP006_VOBJ);
  return raw;
}

// Calculate object temperature based on raw sensor temp and thermopile voltage
double readObjTempC(uint8_t addr) 
{
  double Tdie = readRawDieTemperature(addr);
  double Vobj = readRawVoltage(addr);
  Vobj *= 156.25;  // 156.25 nV per LSB
  Vobj /= 1000000000; // nV -> V
  Tdie *= 0.03125; // convert to celsius
  Tdie += 273.15; // convert to kelvin

  // Equations for calculating temperature found in section 5.1 in the user guide
  double tdie_tref = Tdie - TMP006_TREF;
  double S = (1 + TMP006_A1*tdie_tref + 
      TMP006_A2*tdie_tref*tdie_tref);
  S *= TMP006_S0;
  S /= 10000000;
  S /= 10000000;

  double Vos = TMP006_B0 + TMP006_B1*tdie_tref + 
    TMP006_B2*tdie_tref*tdie_tref;

  double fVobj = (Vobj - Vos) + TMP006_C2*(Vobj-Vos)*(Vobj-Vos);

  double Tobj = sqrt(sqrt(Tdie * Tdie * Tdie * Tdie + fVobj/S));

  Tobj -= 273.15; // Kelvin -> *C
  return Tobj;
}

// Caculate sensor temperature based on raw reading
double readDieTempC(uint8_t addr) 
{
  double Tdie = readRawDieTemperature(addr);
  Tdie *= 0.03125; // convert to celsius
  return Tdie;
}
