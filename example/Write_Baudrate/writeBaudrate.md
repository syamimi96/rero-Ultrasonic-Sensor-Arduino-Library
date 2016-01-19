# WriteBaudrate() #

## Description ##
This function will read the identity of the Ultrasonic Sensor. 

## Include ##
reroSensor_US.h

## Prototype ##
byte writeBaudrate(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from sensor
 
if errStatus=255 ,serial monitor print out "Write Baudrate ERROR!".

if errStatus=0,serial monitor print out "Write Baudrate PASS!".

## Example ##
reroSensor_US US(2,3,8);

byte baudrateWrite;

baudrateWrite= US.ping(102); // read ID 102 control register Baudrate

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Technology-Ultrasonic-Sensor/blob/wiki/example/Error%20Status.md)

