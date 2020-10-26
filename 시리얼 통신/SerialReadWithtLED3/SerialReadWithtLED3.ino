const int LED_R = 9;
const int LED_G = 10;
const int LED_B = 11;
char data;
int red = 255;
int green = 255;
int blue = 255;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  analogWrite(LED_R, red);
  analogWrite(LED_G, green);
  analogWrite(LED_B, blue);
}

void loop() {
  while (Serial.available() > 0) {
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();

    if (Serial.read() == '\n') {
      analogWrite(LED_R, red);
      analogWrite(LED_G, green);
      analogWrite(LED_B, blue);
    }

    Serial.print('(');
    Serial.print(red);
    Serial.print('.');
    Serial.print(green);
    Serial.print('.');
    Serial.print(blue);
    Serial.println(')');
  }
}
