# ReadDistance() #

## Description ##
This function will call the Ultrasonic Ping and measure distance. 

## Include ##
reroSensor_US.h

## Prototype ##
byte pingUS(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from sensor
 
if errStatus =0, ping Ultrasonic will return distance in cm.
if errStatus more than 0,Ping Ultrasonic will fail.
if Ping Ultrasonic measure times out ,Serial monitor will print out 6553.

## Example ##
reroSensor_US US(2,3,8);

word distance;

distance= US.pingUS(102); // call out the function of Ping Ultrasonic with ID = 102(rero Ultrasonic Sensor default ID).

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)
