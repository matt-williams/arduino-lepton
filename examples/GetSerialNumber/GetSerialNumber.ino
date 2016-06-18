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

  uint16_t serialNumber[4];
  lepton.doGetCommand(Lepton::CMD_SYS_FLIR_SERIAL_NUMBER, serialNumber);
  Serial.printf("FLIR Serial Number: %4x %4x %4x %4x\n", serialNumber[0], serialNumber[1], serialNumber[2], serialNumber[3]);
}

void loop() {
  delay(1000);
}
