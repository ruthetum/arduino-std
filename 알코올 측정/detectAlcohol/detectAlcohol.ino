const int MQ3 = A5;
const int LED = 9;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(MQ3, INPUT);
}

void loop() {
  int alco = analogRead(MQ3);
  Serial.print("Current Alcohol : ");
  Serial.println(alco);

  if (alco >= 600) {
    digitalWrite(LED, HIGH);
    delay(100);
  }

  delay(1000);
}
