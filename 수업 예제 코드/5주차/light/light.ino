const int RLED = 9;
const int LIGHT = 0;
const int MIN_LIGHT = 15;
const int MAX_LIGHT = 950;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(LIGHT, INPUT);
}

void loop() {
  val = analogRead(LIGHT);
  Serial.println(val);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 0, 255);
  val = constrain(val, 0, 255);
  analogWrite(RLED, val);
}
