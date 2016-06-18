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
  lepton.syncFrame();
}

uint16_t frameData[80 * 60];

void loop() {
  if (lepton.readFrame(frameData)) {
    Serial.print('.');
  }
}
