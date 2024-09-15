#include <Joystick.h>

//Define Inputs
#define rudderPin A4
#define brakePinL A2
#define brakePinR A0 //Considered Accelerator

/*
Ranges
Rudder - 261 722
BrakeL - 389 503
BrakeR - 297 397
*/

//Joystick(HID ID, Joystick Type, Button Count, Hat Switch Count, Include X, Include Y, Include Z, Include Rx, Include Ry, Include Rz, Include Rudder, Include Throttle, Include Accelerator, Include Brake, Include Steering)

Joystick_ Joystick(0x15, JOYSTICK_TYPE_JOYSTICK, 0, 0, false, false, false, false, false, false, false, false, true, true, true);

const bool initAutoSendState = true;

//Default state for axis
int rudder_ = 0;
int brake_ = 0;
int accelerator_ = 0;

void setup() {

  /*
  pinMode(rudderZ, INPUT);
  pinMode(brakeL, INPUT);
  pinMode(brakeR, INPUT);
*/
  Joystick.begin();
 
}

void loop() {
  //Axis Runtime
  rudder_ = analogRead(rudderPin);
  rudder_ = map(rudder_, 261, 722, 0, 255);
  Joystick.setSteering(rudder_);
  Joystick.setSteeringRange(0,255);

  //Left Brake Pedal
  brake_ = analogRead(brakePinL);
  brake_ = map(brake_, 389, 503, 0, 255);
  Joystick.setBrake(brake_);
  Joystick.setBrakeRange(0,255);


  //Right Brake Pedal "Accelerator"
  accelerator_ = analogRead(brakePinR);
  accelerator_ = map(accelerator_, 297, 397, 0, 255);
  Joystick.setAccelerator(accelerator_);
  Joystick.setAcceleratorRange(0,255);

  //Pole Delay
  delay(10);
}
