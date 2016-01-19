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
  byte baudrate = US.readBaudrate(102);                          //define baudrate as a function to read the baudrate of the sensor.
  Serial.print("Check Read Baudrate Error:");
  Serial.println(US.errStatus);                                  //the standart of the value is 0, if got error the value will be 255.
  if(US.errStatus>0){
    Serial.println("Read Baudrate ERROR!!!");
  }
  else
  {
  Serial.print("Baudrate:");
  Serial.println(baudrate);
  }
  
  delay(1000);
}
