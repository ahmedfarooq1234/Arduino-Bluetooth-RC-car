/*
 * Bluetooth car header
 */

#ifndef BLUETOOTHCAR_HEADER
#define BLUETOOTHCAR_HEADER

#include <Arduino.h>
#define VERSION 0.1

//global variable
extern char recvChar;

//bluetooth_slave.c
void bluetooh_setup(void);
char get_command(void);

//motors.cpp
void motor_setup(void);
void drive_forward(void);
void drive_backward(void);
void drive_left(void);
void drive_right(void);
void drive_stop(void);

#endif

