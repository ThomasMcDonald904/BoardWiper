#include <Wire.h>
#include <Arduino.h>
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "ezButton.h"
#include "lcd/lcd.h"
#include "Encoder.h"
#include "StateMachine.h"

constexpr int SOFTWARE_X_ENDSTOP = 1000;
constexpr int SOFTWARE_Y_ENDSTOP = 700;

constexpr int X_LIMITSWITCH_PIN = 33;
constexpr int Y_LIMITSWITCH_PIN = 32;

constexpr int X_STEPPER_DIRECTION_PIN = 130;
constexpr int X_STEPPER_STEP_PIN = 129;
constexpr int Y_STEPPER_DIRECTION_PIN = 133;
constexpr int Y_STEPPER_STEP_PIN = 132;



AccelStepper *x_stepper = new AccelStepper(AccelStepper::DRIVER, X_STEPPER_STEP_PIN, X_STEPPER_DIRECTION_PIN);
AccelStepper *y_stepper = new AccelStepper(AccelStepper::DRIVER, Y_STEPPER_STEP_PIN, Y_STEPPER_DIRECTION_PIN);
MultiStepper stepperManager;

ezButton *x_limitswitch = new ezButton(X_LIMITSWITCH_PIN);
ezButton *y_limitswitch = new ezButton(Y_LIMITSWITCH_PIN);

// bool HomingState()
// {
// 	int homedAxes = 0;
// 	if (x_limitswitch->isPressed())
//     {
// 		homedAxes += 1;
//        	x_stepper->setCurrentPosition(0);
//     }
//     if (y_limitswitch->isPressed())
//     {
// 		homedAxes += 1;
//        	y_stepper->setCurrentPosition(0);
//     }
// 	return homedAxes == 2;
// }

void setup() {
	Serial.begin(115200);
	// lcd.begin(16, 2);
	// CurrentState = States::Waking;

	// x_stepper->setEnablePin(128);
	// y_stepper->setEnablePin(131);

	// stepperManager.addStepper(*x_stepper);
	// stepperManager.addStepper(*y_stepper);

	// x_limitswitch->setDebounceTime(50);
	// y_limitswitch->setDebounceTime(50);
	// TopMenu.begin(display, displayValue);
}

void loop() {
	// Serial.println("Working!");
// 	switch (CurrentState)
// 	{
// 	case States::Waking:
// 		/* code */
// 		break;
// 	case States::Homing:
// 		if(HomingState())
// 		{
// 			CurrentState = States::Idle;
// 		}
// 		break;
// 	case States::Idle:
// 		break;
// 	case States::Clearing:
// 		break;
// 	default:
// 		break;
// 	}

// 	stepperManager.run();
// 	x_limitswitch->loop();
// 	y_limitswitch->loop();

// 	if (x_stepper->currentPosition() >= SOFTWARE_X_ENDSTOP)
// 	{
// 		x_stepper->disableOutputs();
// 	}
// 	if (y_stepper->currentPosition() >= SOFTWARE_Y_ENDSTOP)
// 	{
// 		y_stepper->disableOutputs();
// 	}
}