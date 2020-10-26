const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
int cmd;
int LED;
int VALUE;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 255);
}

void loop() {
  while (Serial.available() > 0) {
    cmd = Serial.parseInt();

    for (int i=0; i<cmd; i++) {
      LED = Serial.parseInt();
      VALUE = Serial.parseInt();

      if (LED == 0) {
        analogWrite(LED_R, VALUE);
      } else if (LED == 1) {
        analogWrite(LED_G, VALUE);
      } else if (LED == 2) {
        analogWrite(LED_B, VALUE);
      }
    }
  }
}
