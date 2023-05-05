#include "SimpleMenu.h"
#include "LiquidCrystal.h"
#include "movement/movement.h"
#include "Encoder.h"

#define LCD_RS 4
#define LCD_EN 5
#define LCD_D4 0
#define LCD_D5 1
#define LCD_D6 2
#define LCD_D7 3

constexpr int BUTTON_ENCODER_PIN1 = 14;
constexpr int BUTTON_ENCODER_PIN2 = 15;


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

extern LiquidCrystal lcd;
extern Encoder lcd_encoder;

extern SimpleMenu TopMenu;

void display(SimpleMenu *_menu);
void displayValue(SimpleMenu *_menu);