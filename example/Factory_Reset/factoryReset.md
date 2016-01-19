# FactoryReset() #

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
 
if return 0 ,serial monitor print out Factory Reset ERROR!

if return 1,serial monitor print out Factory Reset PASS!

## Example ##
reroSensor_US US(2,3,8);

byte stat;

stat= US.factoryReset(102); // read ID 102 control registor factory Reset

## Find Out ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

