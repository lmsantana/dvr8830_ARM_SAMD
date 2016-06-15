#ifndef RovablesARMMotor_h
#define	RovablesARMMotor_h

#include <Wire.h>
#include <Arduino.h>

#define ADDR_MOTOR_WRITE 224     //0xE0 = 224, value that the digital analyzer show as 0xC0 (datasheet addr)
#define ADDR_MOTOR_READ  225     //0cE1 should return 0xC1 (same idea...)

#define IN1 0
#define IN2 1

class RovablesMotor
{
	public:
		RovablesMotor(uint8_t addr);
		void driveForward (unsigned int spd);
		void brake();
		void driveReverse (unsigned int spd);
		void totalStop();
	private:
		void transmit(uint8_t control_register);
		uint8_t _addr;
		uint8_t _sub_addr_control;		//register addres for voltage setting anf bridge control
		uint8_t _sub_addr_fault;		//register address for reading failures
};

#endif