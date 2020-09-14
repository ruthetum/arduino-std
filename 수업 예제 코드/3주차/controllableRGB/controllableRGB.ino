const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
const int BUTTON = 2;

boolean prevBtn = LOW;
boolean currBtn = LOW;
int MODE = 0;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean prev) {
  boolean curr = digitalRead(BUTTON);
  if (prev != curr) {
    delay(5);
    curr = digitalRead(BUTTON);
  }
  return curr;
}

void setMode(int mode) {
  if (MODE == 1) {
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
  } else if (MODE == 4) {
    analogWrite(LED_R, 127);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 127);
  } else if (MODE == 5) {
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 127);
    analogWrite(LED_B, 127);
  } else if (MODE == 6) {
    analogWrite(LED_R, 127);
    analogWrite(LED_G, 127);
    analogWrite(LED_B, 0);
  } else if (MODE == 7) {
    analogWrite(LED_R, 85);
    analogWrite(LED_G, 85);
    analogWrite(LED_B, 85);
  } else if (MODE == 0) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  }
}

void loop() {
  currBtn = debounce(prevBtn);
  if (prevBtn == LOW && currBtn == HIGH) {
    MODE++;
  }
  prevBtn = currBtn;

  if (MODE == 8) {
    MODE = 0;
  }

  setMode(MODE);
}
