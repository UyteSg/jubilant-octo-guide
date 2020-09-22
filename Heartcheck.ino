#define heartratePin A1
#include "DFRobot_Heartrate.h"

DFRobot_Heartrate heartrate(ANALOG_MODE);
uint8_t rateValue;

void setup() {

Serial.begin(115200);
}

void loop() {


heartrate.getValue(heartratePin);
rateValue = heartrate.getRate();
Serial.println(rateValue);

delay(20);
}
