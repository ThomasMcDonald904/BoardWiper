#include <Arduino.h>
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "ezButton.h"
#include "lcd/lcd.h"
#include "Encoder.h"


const int SOFTWARE_X_ENDSTOP = 1000;
const int SOFTWARE_Y_ENDSTOP = 1000;

const int X_LIMITSWITCH_PIN = 33;
const int Y_LIMITSWITCH_PIN = 32;

const int X_STEPPER_DIRECTION_PIN = 130;
const int X_STEPPER_STEP_PIN = 129;
const int Y_STEPPER_DIRECTION_PIN = 133;
const int Y_STEPPER_STEP_PIN = 132;

const int BUTTON_ENCODER_PIN1 = 14;
const int BUTTON_ENCODER_PIN2 = 15;


AccelStepper *x_stepper = new AccelStepper(AccelStepper::DRIVER, X_STEPPER_STEP_PIN, X_STEPPER_DIRECTION_PIN);
AccelStepper *y_stepper = new AccelStepper(AccelStepper::DRIVER, Y_STEPPER_STEP_PIN, Y_STEPPER_DIRECTION_PIN);
MultiStepper stepperManager;

ezButton *x_limitswitch = new ezButton(X_LIMITSWITCH_PIN);
ezButton *y_limitswitch = new ezButton(Y_LIMITSWITCH_PIN);



void setup() {
	x_stepper->setEnablePin(128);
	y_stepper->setEnablePin(131);

	stepperManager.addStepper(*x_stepper);
	stepperManager.addStepper(*y_stepper);

	x_limitswitch->setDebounceTime(50);
	y_limitswitch->setDebounceTime(50);

	TopMenu.begin(display, displayValue);
}

void loop() {
	stepperManager.run();
	x_limitswitch->loop();
	y_limitswitch->loop();

	if (x_stepper->currentPosition() >= SOFTWARE_X_ENDSTOP)
	{
		x_stepper->disableOutputs();
	}
	
}