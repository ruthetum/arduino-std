const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
char data;
boolean STATE_R = false;
boolean STATE_G = false;
boolean STATE_B = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();

    if (data == '0') {
      STATE_R = false;
      STATE_G = false;
      STATE_B = false;
    } else if (data == '1') {
      STATE_R = !STATE_R;
    } else if (data == '2') {
      STATE_G = !STATE_G;
    } else if (data == '3') {
      STATE_B = !STATE_B;
    } else if (data == '4') {
      STATE_R = true;
      STATE_G = true;
      STATE_B = true;
    }

    digitalWrite(LED_R, STATE_R);
    digitalWrite(LED_G, STATE_G);
    digitalWrite(LED_B, STATE_B);
  }
}
