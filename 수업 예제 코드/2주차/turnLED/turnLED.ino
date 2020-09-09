const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT); // LED pin output으로 설정
  digitalWrite(LED, HIGH); // LED pin High(5V) 설정
}

void loop() {
  for (int i=100;i<=1000; i=i+100) {
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
  }
}
