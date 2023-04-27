#include "SimpleMenu.h"
#include "LiquidCrystal.h"
#include "movement/movement.h"
#include "Encoder.h"

#define LCD_RS 4
#define LCD_EN 21
#define LCD_D4 0
#define LCD_D5 15
#define LCD_D6 16
#define LCD_D7 17

// SimpleMenu MenuSub[3] = {
//   SimpleMenu("varable A",&valueA),
//   SimpleMenu("varable B",&valueB),
//   SimpleMenu("varable C",&valueC)
// };

// SimpleMenu Menu[4] = {
//   SimpleMenu("varable",&mainValue,3,10),
//   SimpleMenu("functions",function),
//   SimpleMenu("sub menu A",3,MenuSub),
//   SimpleMenu("sub menu B",3,MenuSub)
// };

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
extern Encoder lcd_encoder(BUTTON_ENCODER_PIN1, BUTTON_ENCODER_PIN2);

extern SimpleMenu TopMenu(2, MainMenu);

// TopMenu
SimpleMenu MainMenu[1];

// Main Menu
SimpleMenu Movement[2];

// Movement
SimpleMenu Home("Home Axes", homeSteppers);
SimpleMenu MoveAxis[2];

//Move Axis
SimpleMenu XAxisMove("Move X Axis", moveXAxis);
SimpleMenu YAxisMove("Move Y Axis", moveYAxis);

void display(SimpleMenu *_menu){};
void displayValue(SimpleMenu *_menu){};