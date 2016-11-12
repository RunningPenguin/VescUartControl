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

//You have to configure the VESC to APP "UART" and set the baudrate to 256800 the baud rate is hard coded for now in the VescUartControl.cpp
//You have to uncommend the line "#define USE_PATCHED_VESC_FW_2_18" in the file VescUartControl.h

#include <VescUartControl.h>

VescController Vesc1;
VescController Vesc2;

struct bldcLimits limitsVESC1;
struct bldcLimits limitsVESC2;

struct bldcMeasure measuredVESC1;
struct bldcMeasure measuredVESC2;

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
  if (Vesc1.UartGetLimits(limitsVESC1))
  {
    Serial.print("currentMax_VESC1: "); Serial.println(limitsVESC1.currentMax);
    Serial.print("currentMin_VESC1: "); Serial.println(limitsVESC1.currentMin);
    Serial.print("inCurrentMax_VESC1: "); Serial.println(limitsVESC1.inCurrentMax);
    Serial.print("inCurrentMin_VESC1: "); Serial.println(limitsVESC1.inCurrentMin);
    Serial.print("absCurrentMax_VESC1: "); Serial.println(limitsVESC1.absCurrentMax);
    Serial.print("minVin_VESC1: "); Serial.println(limitsVESC1.minVin);
    Serial.print("maxVin_VESC1: "); Serial.println(limitsVESC1.maxVin);
    Serial.print("batteryCutStart_VESC1: "); Serial.println(limitsVESC1.batteryCutStart);
    Serial.print("batteryCutEnd_VESC1: "); Serial.println(limitsVESC1.batteryCutEnd);
    Serial.print("tempFetStart_VESC1: "); Serial.println(limitsVESC1.tempFetStart);
    Serial.print("tempFetEnd_VESC1: "); Serial.println(limitsVESC1.tempFetEnd);
    Serial.print("tempMotStart_VESC1: "); Serial.println(limitsVESC1.tempMotorStart);
    Serial.print("tempMotEnd_VESC1: "); Serial.println(limitsVESC1.tempMotorEnd);
    Serial.print("max_Duty_VESC1: "); Serial.println(limitsVESC1.max_Duty); 
  }
  else
  {
    Serial.println("Could not get Configuration from VESC1");
  }

  delay(200);
  if (Vesc2.UartGetLimits(limitsVESC2))
  {
    Serial.print("currentMax_VESC2: "); Serial.println(limitsVESC2.currentMax);
    Serial.print("currentMin_VESC2: "); Serial.println(limitsVESC2.currentMin);
    Serial.print("inCurrentMax_VESC2: "); Serial.println(limitsVESC2.inCurrentMax);
    Serial.print("inCurrentMin_VESC2: "); Serial.println(limitsVESC2.inCurrentMin);
    Serial.print("absCurrentMax_VESC2: "); Serial.println(limitsVESC2.absCurrentMax);
    Serial.print("minVin_VESC2: "); Serial.println(limitsVESC2.minVin);
    Serial.print("maxVin_VESC2: "); Serial.println(limitsVESC2.maxVin);
    Serial.print("batteryCutStart_VESC2: "); Serial.println(limitsVESC2.batteryCutStart);
    Serial.print("batteryCutEnd_VESC2: "); Serial.println(limitsVESC2.batteryCutEnd);
    Serial.print("tempFetStart_VESC2: "); Serial.println(limitsVESC2.tempFetStart);
    Serial.print("tempFetEnd_VESC2: "); Serial.println(limitsVESC2.tempFetEnd);
    Serial.print("tempMotStart_VESC2: "); Serial.println(limitsVESC2.tempMotorStart);
    Serial.print("tempMotEnd_VESC2: "); Serial.println(limitsVESC2.tempMotorEnd);
    Serial.print("max_Duty_VESC2: "); Serial.println(limitsVESC2.max_Duty); 
  }
  else
  {
    Serial.println("Could not get Configuration from VESC2");
  }
  
  delay(200);
  Serial.println("setup ready");
  delay(400);
}

void loop()
{
  if (Vesc1.UartGetValue(measuredVESC1))
  {
    Serial.print("tempPcb_VESC1: "); Serial.println(measuredVESC1.tempPcb);
    Serial.print("avgMotCur_VESC1: "); Serial.println(measuredVESC1.avgMotorCurrent);
    Serial.print("avgInpCur_VESC1: "); Serial.println(measuredVESC1.avgInputCurrent);
    Serial.print("dutyCycleNow_VESC1: "); Serial.println(measuredVESC1.dutyCycleNow);
    Serial.print("rpm_VESC1: "); Serial.println(measuredVESC1.rpm);
    Serial.print("inVolt_VESC1: "); Serial.println(measuredVESC1.inpVoltage);
    Serial.print("ampHour-_VESC1: "); Serial.println(measuredVESC1.ampHours);
    Serial.print("ampHour+_VESC1: "); Serial.println(measuredVESC1.ampHoursCharged);
    Serial.print("tacho_VESC1: "); Serial.println(measuredVESC1.tachometer);
    Serial.print("tachoAbs_VESC1: "); Serial.println(measuredVESC1.tachometerAbs);
  }
  else
  {
    Serial.println("Failed to get data from VESC1!");
  }

  delay(100);
  if (Vesc2.UartGetValue(measuredVESC2))
  {
    Serial.print("tempPcb_VESC2: "); Serial.println(measuredVESC2.tempPcb);
    Serial.print("avgMotCur_VESC2: "); Serial.println(measuredVESC2.avgMotorCurrent);
    Serial.print("avgInpCur_VESC2: "); Serial.println(measuredVESC2.avgInputCurrent);
    Serial.print("dutyCycleNow_VESC2: "); Serial.println(measuredVESC2.dutyCycleNow);
    Serial.print("rpm_VESC2: "); Serial.println(measuredVESC2.rpm);
    Serial.print("inVolt_VESC2: "); Serial.println(measuredVESC2.inpVoltage);
    Serial.print("ampHour-_VESC2: "); Serial.println(measuredVESC2.ampHours);
    Serial.print("ampHour+_VESC2: "); Serial.println(measuredVESC2.ampHoursCharged);
    Serial.print("tacho_VESC2: "); Serial.println(measuredVESC2.tachometer);
    Serial.print("tachoAbs_VESC2: "); Serial.println(measuredVESC2.tachometerAbs);
  }
  else
  {
    Serial.println("Failed to get data from VESC2!");
  }

Serial.println("end");
while(1);
}
