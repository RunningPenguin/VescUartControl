/*
  Copyright 2016 Tobias Sachs Tobias.Sachs@onlinehome.de

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
*/

/*
 created by:  Tobias Sachs
 Name:      VescUartControlSample.ino
 Created:   22/09/2016
 Author:    TS
*/

//You have to configure the VESCs to APP "UART" and set the baudrate to 256800 the baud rate is hard coded for now in the file VescUartControl.cpp

#include <VescUartControl.h>

VescController Vesc1;
VescController Vesc2;

struct bldcMeasure measuredVESC1;
struct bldcMeasure measuredVESC2;

uint16_t counts = 0;

void setup()
{

  Serial.begin(115200); //begin Serial Console
  delay(600);

  Serial.println("setup begin VESC1");
  Vesc1.begin(&Serial2);
  Vesc1.UartSetCurrent(0.0);
  Vesc1.UartSetCurrentBrake(0.0);
  delay(200);
  Serial.println("setup ready VESC1");

  Serial.println("setup begin VESC2");
  Vesc2.begin(&Serial3);
  Vesc2.UartSetCurrent(0.0);
  Vesc2.UartSetCurrentBrake(0.0);
  delay(200);
  Serial.println("setup ready VESC2");
  
  delay(200);
  Serial.println("setup ready");
  delay(200);
}

void loop()
{

    
  Vesc1.UartSetCurrent(2.0);
  Vesc2.UartSetCurrent(2.0);
  Serial.println("Both motors should be running now");
  delay(200);
  counts++;

  if(counts==20)//should be 4s
  {
    Vesc1.UartSetCurrent(0.0);
    Vesc2.UartSetCurrent(0.0);
    Serial.println("Both motors should stop running now");
    Serial.println("end");
    while(1);
  }

}
