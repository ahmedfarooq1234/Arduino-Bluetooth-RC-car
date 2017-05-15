/*
 *  This code controls 4 DC motors via s L298 Dual H-Bridge motor driver
 *  You can use any 4WD kit as long as your battery has enough power to run the motors and arduino.
 *  This design uses a 7.4v 2200mAh RC battery.
 */
#include "BluetoothCar.h"

int motor_left[]  = {5,6};        // pwm pins on arduino, IN1 and IN2 on motor driver
int motor_right[] = {9,10};       // pwm pins on arduino, IN3 and IN4 on motor driver
int enableL       = 7;            // ENA on motor driver, enables IN1 and IN2 on motor driver (MOTORA)
int enableR       = 8;            // ENB on motor driver, enables IN3 and IN4 on motor driver (MOTORB)

int speed         = 128;          //max speed is 255 = 100% (5v output)

void motor_setup(void)
{                                 // since we are using analogWrite to control the motors, 
                                  // there is no need to set the motor pins as outputs
  pinMode(enableL, OUTPUT);
  pinMode(enableR, OUTPUT);
  digitalWrite(enableL, HIGH);    // keep motors always avaliable 
  digitalWrite(enableR, HIGH);
}

void drive_forward(void)
{
  analogWrite(motor_left[0], speed);
  analogWrite(motor_left[1], 0);

  analogWrite(motor_right[0], speed);
  analogWrite(motor_right[1], 0);
}

void drive_backward(void)
{
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], speed);

  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], speed);
}

void drive_left(void)
{
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], speed);

  analogWrite(motor_right[0], speed);
  analogWrite(motor_right[1], 0);
}

void drive_right(void)
{
  analogWrite(motor_left[0], speed);
  analogWrite(motor_left[1], 0);

  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], speed);  
}

void drive_stop(void)
{
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 0);

  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);  
}
