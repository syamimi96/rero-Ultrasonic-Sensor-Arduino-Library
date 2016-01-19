#include <reroSensor_US.h>                                        //Libary Of Ultrasonic Sensor
#include <SoftwareSerial.h>
reroSensor_US US(2, 3, 8);                                        //define class of reroSensor_US=US (rxpin,txpin,ctrlpin)
void setup() {
  Serial.begin(9600);               
  US.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}
void loop() {
 byte IdWrite=US.writeID(102,103);                                //define IdWrite as a function to write the new id to the sensor.
 Serial.print("Check Write ID Error :");
 Serial.println(US.errStatus);                                    //the standart of the value is 0, if got error the value will be 255.
 if(US.errStatus>0){
  Serial.println("Write ID ERROR!");
 }
 else
 {
  Serial.println("Write ID PASS!");
 }
  delay(1000);
}
