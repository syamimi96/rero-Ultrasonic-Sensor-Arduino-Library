# ReadDistance() #

## Description ##
This function will read the Ultrasonic Ping and display the measured distance. 

## Include ##
reroSensor_US.h

## Prototype ##
byte pingUS(byte ID);

## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
 return packet from sensor
 
if error status =0, Serial monitor will print out the distance in cm.
if error status =255,Serial monitor will print out "Ping Ultrasonic ERROR!".
if Ping Ultrasonic measure times out ,Serial monitor will print out 6553.

## Example ##
reroSensor_US US(2,3,8);

word distance;

distance= US.pingUS(102); // read ID 102 control registor Ping Ultrasonic

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Technology-Ultrasonic-Sensor/blob/wiki/example/Error%20Status.md)
