# dvr8830_ARM_SAMD
Library for using the chip dvr8830 over I2C and ARM based boards

I had some issues with the I2C given by the datasheet, which seemed to be different from what my board 
responded to (using a logic analyzer).
Some of this may be because of the default Wire library of Arduino, since the problem was the 8th bit of the address not being 
sent over the bus, so I had to send "ADDR << 2" to make it work.
