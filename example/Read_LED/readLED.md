# ReadLED() #

## Description ##
This function call out mode of the Ultrasonic Sensor LED. 

## Include ##
reroSensor_US.h

## Prototype ##
byte readLED(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 Return packet from LED register:
 
if errStatus more than 0 ,read ID fail.

if errStatus=0,LED register will return the mode of sensor LED.

## Example ##
reroSensor_US US(2,3,8);

byte LED;

LED= US.readLED(102); // call out the function of readLED with ID = 102(rero Ultrasonic Sensor default ID).

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

