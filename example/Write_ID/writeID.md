# WriteID() #

## Description ##
This function will read the identity of the Ultrasonic Sensor. 

## Include ##
reroSensor_US.h

## Prototype ##
byte ping(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from sensor
 
if errStatus=255 ,serial monitor print out "Read Write ID ERROR!".

if errStatus=0,serial monitor print out "Read Write ID PASS!".

## Example ##
reroSensor_US US(2,3,8);

byte idWrite;

idWrite= US.ping(102); // read ID 102 control register id.

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

