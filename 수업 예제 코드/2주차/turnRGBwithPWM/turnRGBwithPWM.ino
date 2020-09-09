const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  for (int i=100; i>=20; i=i-20){
    int duty = (int)(i / 100.0 * 255);
    for (int cost=300; cost>=100; cost=cost-100) {
      turnLED(LED_R, duty, cost);
      turnLED(LED_G, duty, cost);
      turnLED(LED_B, duty, cost);
    }
  }
}

void turnLED(int LED, int duty, int cost) {
  analogWrite(LED, duty);
  delay(cost);
  analogWrite(LED, 0);
}
