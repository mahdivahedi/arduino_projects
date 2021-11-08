#include <Keypad.h>

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'*','0','#','a'},
  {'1','2','3','b'},
  {'4','5','6','c'},
  {'7','8','9','d'}
};
byte rowPins[ROWS] = {25, 26, 27, 28};
byte colPins[COLS] = {22, 23, 24,29};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int incomingByte = 0;

void setup(){
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
  
void loop(){
  //Keypad Input
  char customKey = customKeypad.getKey();
  if (customKey == '1'){
    digitalWrite(5, HIGH);
    Serial.println("1");
    delay(1000);
    digitalWrite(5, LOW);
  }else if(customKey == '2'){
    digitalWrite(6, HIGH);
    Serial.println("2");
    delay(1000);
    digitalWrite(6, LOW);
  }else if(customKey == '3'){
    digitalWrite(7, HIGH);  
    Serial.println("3");
     delay(1000);
    digitalWrite(7, LOW);
  }else if(customKey == '4'){
    digitalWrite(8, HIGH);
    Serial.println("4");
     delay(1000);
    digitalWrite(8, LOW);
  }else if(customKey == '5'){
    digitalWrite(9, HIGH);
    Serial.println("5");
     delay(1000);
    digitalWrite(9, LOW);
  }else if(customKey == '6'){
    digitalWrite(10, HIGH);
    Serial.println("6");
     delay(1000);
    digitalWrite(10, LOW);
  }else if(customKey == '7'){
    digitalWrite(11, HIGH);
    Serial.println("7");
     delay(1000);
    digitalWrite(11, LOW);
  }else if(customKey == '8'){
    digitalWrite(12, HIGH);
    Serial.println("8");
     delay(1000);
    digitalWrite(12, LOW);
  }else if(customKey == '9'){
    digitalWrite(13, HIGH);
    Serial.println("9");
     delay(1000);
    digitalWrite(13, LOW);
  }else if(customKey == 'a'){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("a");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }else if(customKey == 'b'){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("b");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }else if(customKey == 'c'){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("c");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }else if(customKey == 'd'){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("d");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }

  //Serial Input
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(((char)incomingByte));
    if ((char)incomingByte == '1'){
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
    }else if((char)incomingByte == '2'){
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
    }else if((char)incomingByte == '3'){
      digitalWrite(7, HIGH);  
      delay(500);
      digitalWrite(7, LOW);
    }else if((char)incomingByte == '4'){
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
    }else if((char)incomingByte == '5'){
      digitalWrite(9, HIGH);
      delay(500);
      digitalWrite(9, LOW);
    }else if((char)incomingByte == '6'){
      digitalWrite(10, HIGH);
      delay(500);
      digitalWrite(10, LOW);
    }else if((char)incomingByte == '7'){
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(11, LOW);
    }else if((char)incomingByte == '8'){
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
    }else if((char)incomingByte == '9'){
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
    }else if((char)incomingByte == 'a'){
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }else if((char)incomingByte == 'b'){
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }else if((char)incomingByte == 'c'){
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }else if((char)incomingByte == 'd'){
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }
  }
}
