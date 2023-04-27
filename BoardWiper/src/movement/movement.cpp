#include "movement.h"
#include "AccelStepper.h"
#include "ezButton.h"
#include "lcd/lcd.h"


extern AccelStepper *x_stepper;
extern AccelStepper *y_stepper;
extern ezButton *x_limitswitch;
extern ezButton *y_limitswitch;

void homeSteppers()
{
    x_stepper->setSpeed(-HOMING_SPEED);
    y_stepper->setSpeed(HOMING_SPEED);

    if (x_limitswitch->isPressed())
    {
        x_stepper->setCurrentPosition(0);
    }
    if (y_limitswitch->isPressed())
    {
        y_stepper->setCurrentPosition(0);
    }
}

void moveXAxis()
{
    x_stepper->moveTo(lcd_encoder.read());
}

void moveYAxis()
{

}