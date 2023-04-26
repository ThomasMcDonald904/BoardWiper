#include <Arduino.h>
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "SimpleMenu.h"
#include "LiquidCrystal.h"


const int X_LIMITSWITCH_PIN = 33;
const int Y_LIMITSWITCH_PIN = 32;

const int X_STEPPER_DIRECTION_PIN = 130;
const int X_STEPPER_STEP_PIN = 129;
const int Y_STEPPER_DIRECTION_PIN = 133;
const int Y_STEPPER_STEP_PIN = 132;

#define LCD_RS 4
#define LCD_EN 21
#define LCD_D4 0
#define LCD_D5 15
#define LCD_D6 16
#define LCD_D7 17

AccelStepper x_stepper(AccelStepper::DRIVER, X_STEPPER_STEP_PIN, X_STEPPER_DIRECTION_PIN);
AccelStepper y_stepper(AccelStepper::DRIVER, Y_STEPPER_STEP_PIN, Y_STEPPER_DIRECTION_PIN);

MultiStepper stepperManager;

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);


void setup() {
	x_stepper.setEnablePin(128);
	y_stepper.setEnablePin(131);

	stepperManager.addStepper(x_stepper);
	stepperManager.addStepper(y_stepper);

	pinMode(X_LIMITSWITCH_PIN, INPUT);
	pinMode(Y_LIMITSWITCH_PIN, INPUT);
}

void loop() {

}