#include "lcd.h"

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
