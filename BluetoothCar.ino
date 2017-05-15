/*
 *  Bluetooth remote controlled car.
 *  
 *  This particular kit uses the skid-steer setup. You can modify it in order to 
 *  add functionalities (i.e. turning the fron wheels, or adding a horn)
 *  
 *  To see what all the buttons in the app do, click on the app settings
 *  and scroll all the way down.
 *  
 *  Note: The arduino is powered directly from the battery
 *  
 */
#include "BluetoothCar.h" //user defined library

void setup() {
 Serial.begin(9600);      // serial monitor only used for debuging
 bluetooh_setup();
 motor_setup();
}

void loop() {
  get_command();
  //Serial.println(recvChar); //uncomment for debugging
  switch(recvChar)
  {
    case 'S':         //The RC App send a signal every 50 ms. 'S' is the default signal
      drive_stop();
      break;
    case 'F':         // 'F' is the forward button
      drive_forward();
      break;
    case 'I':         // 'I' is the forward-right button
    case 'H':         // 'H' is the back-left button
    case 'R':         // 'R' is the right button
      drive_right();
      break;
    case 'G':         // 'G' is the forward-left button
    case 'J':         // 'J' is the back-right button
    case 'L':         // 'L' is the left button
      drive_left();
      break;
    case 'B':         // 'B' is the backward button
      drive_backward();
      break;
  }

}


