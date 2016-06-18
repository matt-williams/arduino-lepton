#include <Wire.h>
#include <SPI.h>
#include <Lepton.h>

// Initialize Lepton
// Pin 4 is connected to SDA
// Pin 5 is connected to SCL
// Pin 15 is connected to SPI CS
Lepton lepton(4, 5, 15);

void setup() {
  Serial.begin(9600);

  lepton.begin();

  // Get initial AGC value
  uint16_t agcEnable[2];
  lepton.doGetCommand(Lepton::CMD_AGC_ENABLE, agcEnable);
  Serial.printf("AGC Enable: %4x %4x\n", agcEnable[0], agcEnable[1]);

  // Enable AGC
  agcEnable[0] = 0;
  agcEnable[1] = 1;
  lepton.doSetCommand(Lepton::CMD_AGC_ENABLE, agcEnable, 2);

  // Get updated AGC value
  lepton.doGetCommand(Lepton::CMD_AGC_ENABLE, agcEnable);
  Serial.printf("AGC Enable: %4x %4x\n", agcEnable[0], agcEnable[1]);
}

void loop() {
  delay(1000);
}
