const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  for (int i=1000; i>=200; i=i-200) {
    turnLED(LED_R, i);
    turnLED(LED_G, i);
    turnLED(LED_B, i);
  }
}

void turnLED(int LED, int cost) {
  digitalWrite(LED, HIGH);
  delay(cost);
  digitalWrite(LED, LOW);
}
