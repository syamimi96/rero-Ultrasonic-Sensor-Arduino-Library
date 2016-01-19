# ReadID() #

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
 
if errStatus more than 0 , ping fail.

if errStatus=0,ping success.

## Example ##
reroSensor_US US(2,3,8);

byte id;

id= US.ping(); //call out the function of ping.

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

