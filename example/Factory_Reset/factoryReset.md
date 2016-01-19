#FactoryReset() #

## Description ##
This function will resets the control registers's Ultrasonic Sensor values to factory default.

## Include ##
reroSensor_US.h

## Prototype ##
byte factoryReset(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from ULTRASONIC sensor
 
if return 0 ,Factory Reset Fail.

if return 1, Factory Reset Success.

## Example ##
reroSensor_US US(2,3,8);

byte reset;

reset= US.factoryReset(102); // call out the function of factory reset with ID 102.

## Find Out ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

