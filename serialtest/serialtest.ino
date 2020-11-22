const int LED = 9;
char x;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read();
    
    if (x == 'o') {
      digitalWrite(LED, LOW);
      delay(1000);
    } else if (x == 'x'){
      digitalWrite(LED, HIGH);
      delay(1000);
    }
  }
}
