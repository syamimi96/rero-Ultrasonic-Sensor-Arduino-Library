#include <reroSensor_US.h>                                        //Library Of Ultrasonic Sensor
#include <SoftwareSerial.h>
reroSensor_US US(2, 3, 8);                                        //define class of reroSensor_US=US (rxpin,txpin,ctrlpin)
void setup() {
  Serial.begin(9600);               
  US.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}
void loop() {
  
  byte reset=US.factoryReset(102);                                //define "reset" as a function for reset the memory of the sensor by using factory reset
  Serial.print("Check Factory Reset:");                           
  Serial.println(US.errStatus);                                   //the standart of the value is 0, if got error the value will be 255.
  if(US.errStatus>0){
    Serial.println("Factory Reset ERROR");
  }
  else
  {
    Serial.println("Factory Reset PASS!");
  }
  delay(1000);
}
