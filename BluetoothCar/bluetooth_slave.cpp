/*
 * Simple code designed to receive data from the HC-06 bluetooth receiver
 * URL: https://amazon.com/Pass-Through-Communication-Compatible-Atomic-Market/dp/B00TNOO438
 */
#include "BluetoothCar.h"
#include "SoftwareSerial.h"

#define RxD 2                           // connect to Tx pin on bluetooth receiver 
#define TxD 4                           // connect to Rx pin on bluetooth receiver

SoftwareSerial blueToohSerial(RxD,TxD); //software serial object

char recvChar;                          // saves the value received from the HC-06

void bluetooh_setup(void) 
{
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  blueToohSerial.begin(9600);           // connect to HC-06
  blueToohSerial.flush();               // flush whatever was there before

}

char get_command(void)
{
   if(blueToohSerial.available())     // if there is a connection, read what is being sent
    {
      recvChar = blueToohSerial.read();
    }
    return recvChar;
}

