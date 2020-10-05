const int RLED = 9;
const int GLED = 10;
const int BLED = 11;

const int BTN = 2;
boolean lastBtn = LOW;
boolean currBtn = LOW;
int MODE = 0;

const int LIGHT = 0;
const int MIN_LIGHT = 15;
const int MAX_LIGHT = 950;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(LIGHT, INPUT);
  pinMode(BTN, INPUT);
}

boolean debounce(boolean last) {
  boolean curr = digitalRead(BTN);
  if (last != curr) {
    delay(5);
    curr = digitalRead(BTN);
  }
  return curr;
}

void setMode(int mode) {
  val = analogRead(LIGHT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 0, 255);
  val = constrain(val, 0, 255);

  if (mode==1) {
    analogWrite(RLED, val);
    analogWrite(GLED, 255);
    analogWrite(BLED, 255);
  } else if (mode==2) {
    analogWrite(RLED, 255);
    analogWrite(GLED, val);
    analogWrite(BLED, 255);
  } else if (mode==3) {
    analogWrite(RLED, 255);
    analogWrite(GLED, 255);
    analogWrite(BLED, val);
  } else {
    analogWrite(RLED, 255);
    analogWrite(GLED, 255);
    analogWrite(BLED, 255);
  }
}

void loop() {
  currBtn = debounce(lastBtn);
  if (lastBtn == LOW && currBtn == HIGH) {
    MODE++;
  }
  lastBtn = currBtn;

  if (MODE == 4) {
    MODE = 0;
  }

  setMode(MODE);
  Serial.println(MODE);
  Serial.println(val);
}
