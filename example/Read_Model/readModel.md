# ReadModel() #

## Description ##
The two byte register contains ASCII character to recognize the sensor type. ‘U’,’S’ in this case denotes the ULTRASONIC SENSOR.

## Include ##
reroSensor_US.h

## Prototype ##
word readModel(ID);
  
## Parameters ##
byte ID; //byte ID is ULTRASONIC SENSOR unique ID

## Returns ##
return model L and model H default value

model L return S

model H return U

## Example ##
reroSensor_US US(2,3,8);

char modelHM[3]={0,0,0}; //null terminated string 

word model

model=US.readModel(102);// read ID 102 control registor

type[1]=(char)model&0x00FF;
  
type[0]=(char)(model>>8);

Serial.println(type);
  
## See Also ##
[errStatus](https://github.com/duckwalker/Cytron-Ultrasonic-Sensor-Arduino-Library/blob/wiki/example/Error%20Status.md)

