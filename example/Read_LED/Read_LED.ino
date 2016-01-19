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

  byte led=US.readLED(102);                                   //define ledRead as a function to get the LED mode
  Serial.print("Check Read LED Error:");
  Serial.println(US.errStatus);                                  //the standart of the value is 0, if got error the value will be 255.
  if( US.errStatus>0){
    Serial.println("Read LED ERROR!");
  }
  else
  {
    Serial.print("LED Status:");  
    Serial.println(led);                                    //0=led off, 1=led on ,2=led trigger
  }
  delay(1000);
}
