/*
 * Example code for using the motor drive drv8830 with ARM SAMD arduino based boards
 * I had some issues with the I2C address being different from the specified by the manual,
 * if the same issues do not occur with you, try to change those
 * 
 * 15 Jun 2016
 */

#include <Wire.h>
#include "RovablesARMMotor.h"

//Creating Class motor to handle the motor with I2C addres as parameter
RovablesMotor motor(0xE0);    //Wire library handle 0xE0 as 0xC0 (true value from datasheet)

/*  Methods for the class
 *   ***valid speed numbers are from 6 to 63
 *  motor.driveForward(unsigned int speed);  
 *  motor.driveReverse(unsigned int speed);
 *  motor.brake();
 *  motor.totalStop(); 
 *  
 */

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  delay(60);    //initialization of the I2C bus for the motor drive

  pinMode(R_LED, OUTPUT);
}



void loop() {

  motor.driveForward(6);
  delay(1000);

  motor.brake();
  delay(1000);

  motor.driveReverse(6);
  delay(1000);

  motor.totalStop();
  delay(1000);

}



