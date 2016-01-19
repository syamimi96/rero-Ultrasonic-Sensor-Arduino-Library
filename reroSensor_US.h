#include"Arduino.h"
#include <SoftwareSerial.h>
#ifndef reroSensor_US_h                         //define header name
#define reroSensor_US_h

//*********************************************************************************************
//***********************INSTUCTION ADDRESS****************************************************
//*********************************************************************************************
#define pingInst 0x01                                                 //Ping Instuction
#define readInst 0x02                                                 //Read Instuction
#define writeInst 0x03                                                //Write Instuction
#define baudrateInst 0x04                                             //Baudrate Address
#define factoryResetInst 0x06                                         //Factory Reset Instuction
#define pingUSInst  0x07                                              //Ping Ultrasonic Sensor Instuction
#define LEDAddress  0x0A                                              //LED Address   
#define modelInst (byte)0x00                                          //Sensor Model Instuction
#define IDAddress  0x03                                               //ID Address
#define TxMode LOW                                                    //Trasmit mode
#define RxMode HIGH                                                   //Reseive mode

class reroSensor_US
{
  public:
    byte errStatus;
    byte _rxpin;
    byte _txpin;
    byte _ctrlpin;



    //***************************************
    //=======BEGIN===========================
    //***************************************
    reroSensor_US (byte rxpin, byte txpin, byte ctrlpin);             //protocall of Set pin mode function
    void begin(long baudrate);                                        //Set begin baudrate funtion 



    //***************************************
    //===========Ping/Read Sensor ID=========
    //***************************************
    byte ping(void);                                                  //read ID funtion protocall



    //***************************************
    //========Factory Reset==================
    //***************************************
    byte factoryReset(byte ID);                                       //factory reset function



    //***************************************
    //=======Read LED Status=================
    //***************************************
    byte readLED(byte ID);                                            //Read LED mode function



    //***************************************
    //========Write LED======================
    //***************************************
    byte writeLED(byte ID, byte LED);                                 //Write LED mode function



    //****************************************
    //=======READ DISTANCE====================
    //****************************************
    word pingUS(byte ID);                                             //Read Ultrasonic ping/distance in cm function



    //***************************************
    //======Read Model=======================
    //***************************************
    word readModel(byte ID);                                          //read high low model of the sensor function



    //***************************************
    //===========Read Baudrate==============
    //***************************************
    byte readBaudrate(byte ID);                                       //read baudrate of the sensor function


    //***************************************
    //===========Read Baudrate==============
    //***************************************
   word writeBaudrate(byte ID,word newBaudrate);                      //Write baudrate of the sensor function



    //***************************************
    //===========WRITE ID====================
    //***************************************
    byte writeID(byte ID, byte newID);                                //Write ID function 



};
#endif


