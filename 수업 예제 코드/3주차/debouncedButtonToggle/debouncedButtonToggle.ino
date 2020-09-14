const int LED = 9;
const int BUTTON = 2;

boolean prevBtn = LOW;
boolean currBtn = LOW;
boolean ledOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean prev){
  boolean current = digitalRead(BUTTON);
  if (prev != current) {
    delay(5); // wating debounce
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop() {
  currBtn = debounce(prevBtn);
  if (prevBtn == LOW && currBtn == HIGH) {
    ledOn = !ledOn;
  }
  prevBtn = currBtn;

  digitalWrite(LED, ledOn);
}
