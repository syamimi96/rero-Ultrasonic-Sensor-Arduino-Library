#FactoryReset() #

## Description ##
This function will reset all the control registers's Ultrasonic Sensor values to default value.

## Include ##
reroSensor_US.h

## Prototype ##
byte factoryReset(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from Ultrasonic Sensor factory reset register.
 
if return 0 ,Factory Reset Fail.

if return 1, Factory Reset Success.

## Example ##
reroSensor_US US(2,3,8);

byte reset;

reset= US.factoryReset(102); // call out the function of factory reset with ID = 102(rero Ultrasonic Sensor default ID).

## Find Out ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

