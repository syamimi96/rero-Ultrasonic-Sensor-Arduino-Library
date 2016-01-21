#include "reroSensor_US.h"
SoftwareSerial* reroUSSerial;
//========================================================================================================================
//===========================================PIN MODE=====================================================================
//========================================================================================================================
reroSensor_US::reroSensor_US(byte rxpin, byte txpin, byte ctrlpin)
{
  _rxpin = rxpin;
  _txpin = txpin;
  _ctrlpin = ctrlpin;
}



//=========================================================================================================================

//=============================================BEGIN BAUDRATE==============================================================

//=========================================================================================================================
void reroSensor_US::begin(long baudrate)
{
  byte hardwareSerial;
  if (_rxpin == 0 && _txpin == 1)
  {
    hardwareSerial = true;
    Serial.begin(baudrate);
    while (!Serial);
    Serial.setTimeout(1000);
  }
  else
  {
    hardwareSerial = false;
    pinMode(_rxpin, INPUT);
    pinMode(_txpin, OUTPUT);
    reroUSSerial = new SoftwareSerial(_rxpin, _txpin);
    reroUSSerial->begin(baudrate);
    reroUSSerial->setTimeout(1000);
  }
  pinMode(_ctrlpin, OUTPUT);
  digitalWrite(_ctrlpin, TxMode);
}




//=========================================================================================================================

//=============================================PING/READ SENSOR ID=========================================================

//=========================================================================================================================
byte reroSensor_US::ping(void) {
  byte buff[6];
  while (reroUSSerial->available()) {                              //clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);                                  //Set control pin to Tx mode

  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFE);                                      //0xFE = global ID
  reroUSSerial->write(0x02);
  reroUSSerial->write(pingInst);                                 //ping insturution
  byte checksum = (0xFF - 0xFE - 0x02 - pingInst);               //checksum equetion
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);                                //Set control pin to Rx mode

  int nbyte = reroUSSerial->readBytes(buff, 6);                  //return packet

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0);
  }
  else
  {
    errStatus = buff[4];                                         //buff[4]=error buffer
    return (buff[2]);                                            //return id buffer
  }
}



//=========================================================================================================================

//=============================================FACTORY RESET===============================================================

//=========================================================================================================================


byte reroSensor_US::factoryReset(byte ID) {
  byte buff[6];
  while (reroUSSerial->available()) {                       //clear noise
    reroUSSerial->read();
  }
  //send intruction
  digitalWrite(_ctrlpin, TxMode);                          //Set control pin to Tx mode
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                                 //ID of the sensor
  reroUSSerial->write(0x02);                               //length
  reroUSSerial->write(factoryResetInst);                   //factory reset insturution
  byte checksum = (0xFF - ID - 0x02 - factoryResetInst);   //checksum eqution
  reroUSSerial->write(checksum);
  digitalWrite(_ctrlpin, RxMode);                          //Set control pin to Rx mode

  int nbyte = reroUSSerial->readBytes(buff, 6);            //return packet

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else
  {
    errStatus = buff[4];                                    //buff[4]=error buffer
    return (1);
  }
}



//=========================================================================================================================

//=============================================READ LED STATUS=============================================================

//=========================================================================================================================

byte reroSensor_US::readLED(byte ID) {
  byte buff[7];
  while (reroUSSerial->available()) {                                   //Clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);                                       //Set control pin to tx mode/
  reroUSSerial->write(0xFF);          
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                                             //sensor ID
  reroUSSerial->write(0x04);                                           
  reroUSSerial->write(readInst);                                       //read insturution
  reroUSSerial->write(LEDAddress);                                     //LED Address
  reroUSSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - LEDAddress - 0x01);   //checksum
  reroUSSerial->write(checksum);                                       

  digitalWrite(_ctrlpin, RxMode);                                      //Set control pin to rx mode
  byte nbyte = reroUSSerial->readBytes(buff, 6);                       //return packet

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];                                               //buff[4]
    return buff[5];                                                    //return buff[5] = led mode buffer
  }
}



//=========================================================================================================================

//=============================================WRITE LED===================================================================

//=========================================================================================================================
byte reroSensor_US::writeLED(byte ID, byte LED) {
  byte buff[7];
  while (reroUSSerial->available()) {
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                                                      //Sensor ID
  reroUSSerial->write(0x04);
  reroUSSerial->write(writeInst);                                               //write instrution
  reroUSSerial->write(LEDAddress);                                              //LED Address
  reroUSSerial->write(LED);                                                     //LED Mode
  byte checksum = (0xFF - ID - 0x04 - writeInst - LEDAddress - LED);            //Checksum
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);                                               //Set control pin to Rx Mode
  byte nbyte = reroUSSerial->readBytes(buff, 6);                                //return packet

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else {
    errStatus = buff [4];                                                       //buff[4]=error buffer
    return buff[4];                                                             //return error buffer
  }
}



//=========================================================================================================================

//=============================================READ DISTANCE===============================================================

//=========================================================================================================================

word reroSensor_US::pingUS(byte ID) {               //word because is using 16bit
  byte buff[8];
  word distance;
  word cm;                                          
  while (reroUSSerial->available()) {               //clear noise
    reroUSSerial->read();
  }
  digitalWrite(_ctrlpin, TxMode);                   //set control pin to Tx mode
  reroUSSerial->write(0xFF);                        
  reroUSSerial->write(0xFF);                        
  reroUSSerial->write(ID);                          //Sensor ID
  reroUSSerial->write(0x02);                        
  reroUSSerial->write(pingUSInst);                  //Ultrasonic ping Instrution
  byte checksum = (0xFF - ID - 0x02 - pingUSInst);  //checksum
  reroUSSerial->write(checksum);
  
  digitalWrite(_ctrlpin, RxMode);                   //Set control pin to Rx mode
  byte nbyte = reroUSSerial->readBytes(buff, 8);    //return packet
  if (nbyte < 8) {
    errStatus = (0xFF);
    return (0xFFFF);
  }
  else {
    distance = buff[6];         //Lower buff
    distance <<= 8;             //Combination of LOWER bit and HIGH bit to 16bit
    distance |= buff[5];        //High buff
    cm = distance / 10;         //formula to get the centimeter
    return (cm);                //return the value of the distance
    errStatus = buff[4];        //buff[4]=error buff
  }
}



//=========================================================================================================================

//=============================================READ MODEL OF SENSOR========================================================

//=========================================================================================================================
word reroSensor_US::readModel(byte ID) {
  byte buff[7];
  word mode;
  while (reroUSSerial->available()) {               //clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);                   //Set control pin to Tx mode
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                          //Sensor ID
  reroUSSerial->write(0x04);
  reroUSSerial->write(readInst);                    //read instrution
  reroUSSerial->write(modelInst);                   //model address
  reroUSSerial->write(0x02);
  byte checksum = (0xFF - ID - 0x04 - readInst - modelInst - 0x02); //checksum
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);                   //Set control pin to Rx mode
  byte nbyte = reroUSSerial->readBytes(buff, 7);    //return packet 

  if (nbyte < 7) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    mode = buff[5];                             //Lower buff
    mode <<= 8;                                 //Combination of LOWER bit and HIGH bit to 16bit
    mode |= buff[6];                            //High buff
    return (mode);                              //return the reading of the mode
    errStatus = buff[4];                        //buff[4]=error buffer
  }
}



//=========================================================================================================================

//=============================================READ BAUDRATE===============================================================

//=========================================================================================================================

byte reroSensor_US::readBaudrate(byte ID) {
  byte buff[7];
  while (reroUSSerial->available()) {         //clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);             //Set control pin to Tx mode
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                    //Sensor ID
  reroUSSerial->write(0x04);
  reroUSSerial->write(readInst);             //read insturution
  reroUSSerial->write(baudrateInst);         //baudrate address
  reroUSSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - baudrateInst - 0x01);   //checksum equation
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);              //Set control pin to Rx mode
  byte nbyte = reroUSSerial->readBytes(buff, 6);     //return packet

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];                     //buff[4]=error buffer
    return buff[5];                          //return baudrate reading buffer
  }
}



//=========================================================================================================================

//=============================================WRITE BAUDRATE==============================================================

//=========================================================================================================================
word reroSensor_US::writeBaudrate(byte ID, word newBaudrate) {
  byte buff[7];
  while (reroUSSerial->available()) {           //clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);               //Set control pin to Tx mode
  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                      //Sensor ID
  reroUSSerial->write(0x04);
  reroUSSerial->write(writeInst);               //write insturution
  reroUSSerial->write(baudrateInst);            //baudrate address
  reroUSSerial->write(newBaudrate);             //new baudrate value
  byte checksum = (0xFF - ID - 0x04 - writeInst - baudrateInst - newBaudrate);   //checksum equetion
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);               //Set control pin to Rx mode
  byte nbyte = reroUSSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else {
    errStatus = buff [4];                    //buff[4]=error buffer
    return buff[4];                          //return error buffer
  }
}


//=========================================================================================================================

//=============================================WRITE ID====================================================================

//=========================================================================================================================
byte reroSensor_US::writeID(byte ID, byte newID) {
  byte buff[7];
  while (reroUSSerial->available()) {     //clear noise
    reroUSSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);         //Set control pin to Tx mode

  reroUSSerial->write(0xFF);
  reroUSSerial->write(0xFF);
  reroUSSerial->write(ID);                //sensor ID
  reroUSSerial->write(0x04);
  reroUSSerial->write(writeInst);         //Write intrustion
  reroUSSerial->write(IDAddress);         //ID Address
  reroUSSerial->write(newID);             //New ID value
  byte checksum = (0xFF - ID - 0x04 - writeInst - IDAddress - newID); //checksum equation
  reroUSSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);         //Set control pin to Rx mode

  byte nbyte = reroUSSerial->readBytes(buff, 6);        //return packet

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (buff[4]);
  }
  else
  {
    errStatus = buff[4];                     //buff[4]=error buffer
    return (0);
  }
}

