#include <Arduino.h>
#include <Wire.h>
#include "RovablesARMMotor.h"

RovablesMotor::RovablesMotor(uint8_t addr)
{
	_addr = addr;
	_sub_addr_control = 0x00;
	_sub_addr_fault = 0x01;
}

void RovablesMotor::transmit(uint8_t control_register)
{
	Wire.beginTransmission(_addr); 		// transmit to register write
	Wire.write(_sub_addr_control);      // puts Control register addres in the buffer
	Wire.write(control_register);       // puts the velocity in the buffer
	Wire.endTransmission(true);         // send the data and free the bus
}

void RovablesMotor::driveForward(unsigned int spd)
{
	if (spd < 6) spd = 6;
	if (spd > 63) spd = 63;
	uint8_t b_spd = spd;
	b_spd = (b_spd<<2)|(0x00<<IN2)|(0x01<<IN1);

	transmit(b_spd);
}

void RovablesMotor::driveReverse(unsigned int spd)
{
	if (spd < 6) spd = 6;
	if (spd > 63) spd = 63;
	uint8_t b_spd = spd;
	b_spd = (b_spd<<2)|(0x01<<IN2)|(0x00<<IN1);

	transmit(b_spd);
}

void RovablesMotor::brake()
{
	uint8_t b_spd = (0x01<<IN2)|(0x01<<IN1);

	transmit(b_spd);
}

void RovablesMotor::totalStop()
{
	uint8_t b_spd = (0x00<<IN2)|(0x00<<IN1);

	transmit(b_spd);
}