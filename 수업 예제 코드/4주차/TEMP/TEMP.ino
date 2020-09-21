const int LED_R = 11;
const int LED_G = 10;
const int LED_B = 9;
const int TEMP = 0;
int val = 0;

const int LOWER_BOUND = 139;
const int UPPER_BOUND = 147;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  val = analogRead(TEMP);
  Serial.println(val);
  if (val < LOWER_BOUND) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_R, LOW);
  } else if (val > UPPER_BOUND) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_R, HIGH);
  } else {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_R, HIGH);
  }
}
