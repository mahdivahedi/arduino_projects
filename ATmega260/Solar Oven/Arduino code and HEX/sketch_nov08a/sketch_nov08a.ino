#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo; 
const byte row = 4;
const byte col = 4;
char hexaKeys[row][col] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'#','0','=','+'}
};
byte rowPins[row] = {37, 35, 33, 31};
byte colPins[col] = {29, 27, 25, 23};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, row, col); 
int tempPin = 0;
const int buzzer = 7;
int num = 0;
int temp = 0;
float tempC = -273;
LiquidCrystal lcd(13, 12, 8, 9, 10, 11);
void setup()
{
  myservo.attach(0);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}
void loop()
{
  int time1 = 0;
  char customKey = customKeypad.getKey();
  if (customKey == '1' || customKey == '2' || customKey == '3' || customKey == '4' || customKey == '5' || customKey == '6' || customKey == '7' || customKey == '8' || customKey == '9' || customKey == '0'){
     num = num * 10 + (customKey - 48);  
  }else if(customKey == '='){
     temp = num;
     num = 0;
     lcd.setCursor(0, 0);
     lcd.print(temp);
  }else if(customKey == '#') {
     time1 = num * 1000;
     num = 0;
     lcd.setCursor(0, 0);
     lcd.print(time1);
     delay(1000);
     while(tempC < temp){
        int tempReading = analogRead(tempPin);
        double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
        tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );
        tempC = tempK - 130;
        lcd.setCursor(0, 0);
        lcd.print("Temp         C  ");
        lcd.setCursor(6, 0);
        lcd.print(tempC);
        lcd.setCursor(0, 1);
        lcd.print(temp);
     }
     delay(time1);
     myservo.write(180);
     tone(buzzer, 1000);
     delay(1000);
     noTone(buzzer);
     delay(1000);
  }
}
