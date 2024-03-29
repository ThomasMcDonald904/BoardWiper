#include "lcd.h"

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
Encoder lcd_encoder(BUTTON_ENCODER_PIN1, BUTTON_ENCODER_PIN2);

SimpleMenu MoveAxees[2] = 
{
    SimpleMenu("Move Y Axis", moveXAxisWithEncoder),
    SimpleMenu("Move Y Axis", moveYAxisWithEncoder)
};

SimpleMenu Movement[3] = 
{
    SimpleMenu("Home Axes", homeSteppers),
    SimpleMenu("Move Axes", 2, MoveAxees),
    SimpleMenu("Clear", clear)
};

SimpleMenu MainMenu[1] = 
{
    SimpleMenu("Movement", 3, Movement) 
};

SimpleMenu TopMenu(1, MainMenu);

void display(SimpleMenu *_menu)
{
  lcd.clear();
  lcd.print(">");
  lcd.print(_menu->name);

  SimpleMenu *next = TopMenu.next();
  if(next != NULL)
  {
    lcd.setCursor(1,1);
    lcd.print(next->name);
  }
}

void displayValue(SimpleMenu *_menu)
{
  lcd.clear();
  lcd.print(_menu->name);
  lcd.setCursor(0,1);
  lcd.print(_menu->getValue());
}
