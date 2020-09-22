
/************************************************************************************************************!
  @file DFRobot_Heartrate.h
  @brief DFRobot_Heartrate.h detailed description for Heartrate.cpp

   This is written for the heart rate sensor the company library. Mainly used for real
   time measurement of blood oxygen saturation, based on measured values calculate heart rate values.

  @author linfeng(Musk.lin@dfrobot.com)
  @version  V1.1
  @date  2016-8-16
  @version  V1.0
  @date  2015-12-24
**************************************************************************************************************/
#define heartratePin A1

#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "DFRobot_Heartrate.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
DFRobot_Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE

// Init custom chars
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};

double counter = 0;
double maximum = 0;
double minimum = 10000;
double x = 0;
bool crestStart = false, firstMaxBeat = true, firstMinBeat = true;


void setup() {
  lcd.begin(); // initialize the LCD
  lcd.backlight(); // Turn on the blacklight and sanity check.
  lcd.createChar(3, heart);
  lcd.setCursor(0, 0);
  lcd.write(3);
  Serial.begin(115200);
}

void loop() {
  x = millis();
 if (x == 60000)
   x = 0;
  double rateValue;
  heartrate.getValue(heartratePin); ///< A1 foot sampled values
  rateValue = heartrate.getRate(); ///< Get heart rate value */
  if(firstMaxBeat){
    maximum = max(maximum, rateValue);
    if(maximum > rateValue)firstMaxBeat = false;
  }
  if(firstMinBeat){
    minimum = min(maximum, rateValue);
    if(minimum < rateValue)firstMinBeat = false;
  }
  if((maximum - rateValue) <= 0 && !crestStart){
    counter++;
    Serial.print("kek\n");
    crestStart = true;
  }
  if((rateValue - minimum) <= 0 && crestStart){
    Serial.print("!kek\n");
    crestStart = false;
  }
  Serial.println(counter / x);
}

/******************************************************************************
  Copyright (C) <2015>  <linfeng>
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  Contact: Musk.lin@dfrobot.com
 ******************************************************************************/
