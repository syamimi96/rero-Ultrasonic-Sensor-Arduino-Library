# WriteBaudrate() #

## Description ##
This function will read the identity of the Ultrasonic Sensor. 

## Include ##
reroSensor_US.h

## Prototype ##
byte writeBaudrate(byte ID,byte newBaudrate);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID.

byte newBaudrate;//rero Ultrasonic Sensor new baudrate.

## Returns ##
 Return packet of baudrate register:
 
if errStatus more than 0,write baudrate fail.

if errStatus=0,write baudrate success.

## Example ##
reroSensor_US US(2,3,8);

byte baudrateWrite;

baudrateWrite= US.ping(102,103);// call out the function of write baudrate with ID = 102(rero Ultrasonic Sensor default ID), Standart value of baudrate =103(19200).

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)
