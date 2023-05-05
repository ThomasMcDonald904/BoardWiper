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
    x_stepper->setSpeed(-HOMING_SPEED);
    y_stepper->setSpeed(HOMING_SPEED);
    CurrentState = States::Homing;
}

void moveXAxis()
{
    x_stepper->moveTo(lcd_encoder.read());
}

void moveYAxis()
{

}