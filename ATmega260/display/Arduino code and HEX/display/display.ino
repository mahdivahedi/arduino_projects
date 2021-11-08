/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','/'},
  {'4','5','6','*'},
  {'7','8','9','-'},
  {'#','0','=','+'}
};
byte rowPins[ROWS] = {25, 26, 27, 28};
byte colPins[COLS] = {22, 23, 24,29};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int incomingByte = 0;
int counter = 0;
int pass =0;//password=1234
int y=0;
int num1=0;
int num2=0;
int number=0;
int action;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  while(1){
    lcd.setCursor(counter,y);
    lcd.print("Amir Askari");
    delay(300);
    lcd.clear();
    counter++;
    if (counter == 16){
      y++;
      counter=0;
    }
    if(y==2){
      break;
    }
  }
  counter=0;
}

void loop() {
  lcd.setCursor(counter, 0);
  char customKey = customKeypad.getKey();
  if (customKey == '1'){
    lcd.print('1');
    counter++;
    if(counter==1){
      pass++;
    }
    if(number==0){
      number=1;
    }else{
      number=number*10+1;
    }
  }else if(customKey == '2'){
    lcd.print('2');
    counter++;
    if(counter==2){pass++;}
    if(number==0){
      number=2;
    }else{
      number=number*10+2;
    }
  }else if(customKey == '3'){
    lcd.print('3');
    counter++;
    if(counter==3){pass++;}
    if(number==0){
      number=3;
    }else{
      number=number*10+3;
    }
  }else if(customKey == '4'){
    lcd.print('4');
    counter++;
    if(counter==4){pass++;}
    if(number==0){
      number=4;
    }else{
      number=number*10+4;
    }
  }else if(customKey == '5'){
    lcd.print('5');
    counter++;
    if(number==0){
      number=5;
    }else{
      number=number*10+5;
    }
  }else if(customKey == '6'){
    lcd.print('6');
    counter++;
    if(number==0){
      number=6;
    }else{
      number=number*10+6;
    }
  }else if(customKey == '7'){
    lcd.print('7');
    counter++;
    if(number==0){
      number=7;
    }else{
      number=number*10+7;
    }
  }else if(customKey == '8'){
    lcd.print('8');
    counter++;
    if(number==0){
      number=8;
    }else{
      number=number*10+8;
    }
  }else if(customKey == '9'){
    lcd.print('9');
    counter++;
    if(number==0){
      number=9;
    }else{
      number=number*10+9;
    }
  }else if(customKey == '0'){
    lcd.print('0');
    counter++;
    if(number==0){
      number=0;
    }else{
      number=number*10+0;
    }
  }else if(customKey == '#'){
    if(pass==4){
      lcd.setCursor(0, 1);
      lcd.print("correct password");
      
    }else{
      lcd.setCursor(0, 1);
      lcd.print(" wrong password ");
    }
    num1=0;
    num2=0;
    number=0;
    delay(2000);
    pass=0;
    lcd.clear();
    lcd.setCursor(0, 0);
    counter=0;
  }else if(customKey == '/'){
    lcd.print('/');
    counter++;
    num1=number;
    number=0;
    action=1;
  }else if(customKey == '*'){
    lcd.print('*');
    counter++;
    num1=number;
    number=0;
    action=2;
  }else if(customKey == '-'){
    lcd.print('-');
    counter++;
    num1=number;
    number=0;
    action=3;
  }else if(customKey == '+'){
    lcd.print('+');
    counter++;
    num1=number;
    number=0;
    action=4;
  }else if(customKey == '='){
    
    num2=number;
    if(action==1){
      number=num1/num2;  
    }else if(action==2){
      number=num1*num2;
    }else if(action==3){
      number=num1-num2;
    }else if(action==4){
      number=num1+num2;
    }
   // delay(2000); 
    lcd.print(" ="); lcd.print(number);
    lcd.setCursor(0, 1);  
    lcd.print(number); 
    counter=0;
    number=0;
    num1=0;
    num2=0;
    action="";
    delay(2000);
    lcd.clear();
  }  
}
