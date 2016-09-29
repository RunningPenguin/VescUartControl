/*
	Copyright 2015 - 2016 Andreas Chaitidis Andreas.Chaitidis@gmail.com
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
 created by:	Andreas Chaitidis
 derived by:	Tobias Sachs
 Name:			local_datatypes.h
 Created:		22/09/2016
 Author:		TS
*/

#ifndef LOCAL_DATATYPES_H_
#define LOCAL_DATATYPES_H_

// Added by AC to store measured values
struct bldcMeasure
{
	float tempPcb;
	float avgMotorCurrent;
	float avgInputCurrent;
	float dutyCycleNow;
	int32_t rpm;
	float inpVoltage;
	float ampHours;
	float ampHoursCharged;
	int32_t tachometer;
	int32_t tachometerAbs;
};

#if defined (USE_PATCHED_VESC_FW_2_18)
// Added by AC to store measured values
struct bldcLimits
{
	int32_t currentMax;
	int32_t currentMin;
	int32_t inCurrentMax;
	int32_t inCurrentMin;
	int32_t absCurrentMax;
	int32_t minVin;
	int32_t maxVin;
	float batteryCutStart;
	float batteryCutEnd;
	int32_t tempFetStart;
	int32_t tempFetEnd;
	int32_t tempMotorStart;
	int32_t tempMotorEnd;
	int32_t max_Duty;
};
#endif //if defined (USE_PATCHED_VESC_FW_2_18)

#endif
