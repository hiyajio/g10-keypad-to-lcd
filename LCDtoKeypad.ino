#include <Keypad.h>
#include <LiquidCrystal.h>
#include "pitches.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(45, 43, 41, 39, 37, 35);

int buzzer = 34;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}
  
void loop(){
  lcd.setCursor(0, 1);
  char key = keypad.getKey();
  
  if (key){
    lcd.print(key);
    tone(buzzer, NOTE_C6, 700);
  }
}
