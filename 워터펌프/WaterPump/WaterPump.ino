const int PUMP_L = 8;
const int PUMP_R = 9;

void setup() {
  pinMode(PUMP_L, OUTPUT);
  pinMode(PUMP_R, OUTPUT);
}

void loop() {
  analogWrite(PUMP_L, 0); // 0V
  analogWrite(PUMP_R , 150); // 3V
//  delay(2000);
}
