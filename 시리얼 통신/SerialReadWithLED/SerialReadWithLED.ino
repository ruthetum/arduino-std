const int LED = 9;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
  
    if (data == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    } else if (data == '0'){ // enter 입력하면 개행문자까지 전송되기 때문에 else if 처리
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
  
}
