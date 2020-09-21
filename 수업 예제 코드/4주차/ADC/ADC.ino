const int POT = 0;
const int LED = 9;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(POT);
  int result = int (val * 255 / 1023.0);
  
  analogWrite(LED, result); 
  delay(10);
}
