/* 
    TimoChess - switch pressed detector
    Read Matrix and output the letter/number of the pressed button
    Xavier Hosxe 2017
    MIT License !!!
*/


const int letterPins[] = { PIN_B2, PIN_B1, PIN_F2, PIN_F1, PIN_F0, PIN_A6, PIN_A5, PIN_A4 };
const int numberPins[] = { PIN_D6, PIN_D7, PIN_E0, PIN_E1, PIN_C0, PIN_C1, PIN_C2, PIN_C3 };

int previousLetter = -1;
int previousNumber = -1;

void setup() {
  Serial.begin(9600);
}


void loop() {
  // Read letter
  for (int k=0; k<8; k++) {
    // number output
    pinMode(numberPins[k], OUTPUT);
    digitalWrite(numberPins[k], LOW);    
    // letter input
    pinMode(letterPins[k], INPUT_PULLUP);
  }

  int letter = -1;
  for (int k=0; k<8; k++) {
    if (digitalRead(letterPins[k]) == LOW) {
      letter = k;
    }
  }  

  delay(5);

  // Read Number
  for (int k=0; k<8; k++) {
    // number output
    pinMode(letterPins[k], OUTPUT);
    digitalWrite(letterPins[k], LOW);    
    // letter input
    pinMode(numberPins[k], INPUT_PULLUP);
  }

  int number = -1;
  for (int k=0; k<8; k++) {
    if (digitalRead(numberPins[k]) == LOW) {
      number = k;
    }
  }  

  delay(5);

  if (number != -1 && letter != -1) {
    if (number != previousNumber || letter != previousLetter) {
      Keyboard.print((char) ('a' + letter));
      delay(5);
      Keyboard.print((char) ('1' + number));
      previousNumber = number;
      previousLetter = letter;
    }
  }
}
