#include "movement.h"
#include "AccelStepper.h"
#include "ezButton.h"
#include "lcd/lcd.h"
#include "StateMachine.h"

const int HOMING_SPEED = 10;
extern AccelStepper *x_stepper;
extern AccelStepper *y_stepper;
extern ezButton *x_limitswitch;
extern ezButton *y_limitswitch;

void homeSteppers()
{
    CurrentState = States::Homing;
    x_stepper->setSpeed(-HOMING_SPEED);
    y_stepper->setSpeed(HOMING_SPEED);
}

void moveXAxisWithEncoder()
{
    x_stepper->moveTo(lcd_encoder.read());
}

void moveYAxisWithEncoder()
{
    y_stepper->moveTo(lcd_encoder.read());
}

void clear()
{
    CurrentState = States::Clearing;
}