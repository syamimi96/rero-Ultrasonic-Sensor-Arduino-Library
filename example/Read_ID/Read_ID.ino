#include <reroSensor_US.h>                                        //Libary Of Ultrasonic Sensor
#include <SoftwareSerial.h>
reroSensor_US US(2, 3, 8);                                        //define class of reroSensor_US=US (rxpin,txpin,ctrlpin)
void setup() {
  Serial.begin(9600);               
  US.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Output Pin Mode
  delay(1000);
}
void loop() {
  byte id=US.ping();                                              //define id as the function to read the id of the sensor.
  Serial.print("Ping Sensor Status:");
  Serial.println(US.errStatus);                                   //the standart of the value is 0, if got error the value will be 255.

  if(US.errStatus>0){
    Serial.println("Ultrasonic Sensor Not Detected!");
  }
  else
  {
    Serial.println("Ultrasonic Sensor Detected!");
    Serial.print("Ultrasonic ID:");
    Serial.println(id);
  }
  
  delay(1000);
}
