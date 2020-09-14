const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;

const int BUTTON_R = 2;
const int BUTTON_G = 3;
const int BUTTON_B = 4; 

boolean prevBtns[3] = {LOW, LOW, LOW};
boolean currBtns[3] = {LOW, LOW, LOW};
int MODE = 0;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  pinMode(BUTTON_R, INPUT);
  pinMode(BUTTON_G, INPUT);
  pinMode(BUTTON_B, INPUT);
}

boolean debounce() {
  boolean prev[3] = {
    digitalRead(BUTTON_R),
    digitalRead(BUTTON_G),
    digitalRead(BUTTON_B)
  };

  delay(5);

  boolean curr[3] = {
    digitalRead(BUTTON_R),
    digitalRead(BUTTON_G),
    digitalRead(BUTTON_B)
  };

  for (int i=0; i<3; i++) {
    if (prevBtns[i] != prev[i]) {
      currBtns[i] = curr[i];
    }
  }
}

void setMode(int mode) {
  if (MODE == 0) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  } else if (MODE == 1) {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  } else if (MODE == 2) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  } else if (MODE == 3) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  } 
}

void loop() {
  debounce();

  for (int i=0; i<3; i++) {
    if (prevBtns[i] == LOW && currBtns[i] == HIGH) {
      MODE = i+1;
    } else {
      MODE = MODE;
    }

    prevBtns[i] = currBtns[i];
  }
  
  setMode(MODE);
}
