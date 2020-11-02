#include <LiquidCrystal.h>

char skku[5] = "SKKU";

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  for (int i=0; i<32; i++) {
    lcd.clear();
    int row = i/16;
    int col = i%16;

    lcd.setCursor(col, row);
    lcd.print(skku);

    if (col > 12) {
      lcd.setCursor(0, 1-row);
      lcd.print(skku[15-col+1]);
    }
    
    delay(500);
  }
}
