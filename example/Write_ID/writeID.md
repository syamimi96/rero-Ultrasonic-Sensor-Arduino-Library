# WriteID() #

## Description ##
This function call out the ID of rero Ultrasonic Sensor. 

## Include ##
reroSensor_US.h

## Prototype ##
byte writeID(byte ID,byte newID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

byte newID;//rero Ultrasonic Sensor new ID
## Returns ##
 return packet from sensor
 
if errStatus more than 0,read write ID fail.

if errStatus=0,read write ID success.

## Example ##
reroSensor_US US(2,3,8);

byte idWrite;

idWrite= US.writeID(102,103);// call out the function of write ID with ID = 102(rero Ultrasonic Sensor default ID),103=rero Ultrasonic sensor new ID.

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

