# BaudRate() #

## Description ##
This function is reading baudrate's Ultrasonic Sensor 

## Include ##
reroSensor_US.h

## Prototype ##
byte readBaudrate(byte ID);

## Parameters ##

byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
Return BaudRate Value Data

|RegisterValue(Hex)|BaudRate(bps)|
|:-----------------|:------------|
|3   (0x03)|500,000       |
|4   (0x04)|400,000       |
|7   (0x07)|250,000       |
|9   (0x09)|200,000       |
|16  (0x10)|115,200       |
|34  (0x22)|57,600        |
|103 (0x67)|19,200        |
|207 (0xCF)|9600          |


## Example ##
reroSensor_US US(2,3,8);

byte baudrateRead;

baudrateRead= US.readBaudrate(102); // read ID 102 control registor Baudrate Value

## See Also ##

[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)



