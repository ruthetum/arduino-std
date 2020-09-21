const int LED_R = 11;
const int LED_G = 10;
const int LED_B = 9;
const int TEMP = 0;
const int POT = 5;
int valT = 0;
int valP = 0;

const int LOWER_BOUND = 158;
const int UPPER_BOUND = 159;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  valP = analogRead(POT);
  valT = analogRead(TEMP);
  Serial.print(valP);
  Serial.print(" ");
  Serial.println(valT);
  int res = 0;

  if (valT <156) {
    res = 255;
  } else if (valT <= 158) {
    res = 170; 
  } else if (valT <= 160) {
    res = 85;
  } else {
    res = 0;
  }
    
  
  if (valP < 350) {
    Serial.println(1);
    analogWrite(LED_R, res);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, 255);
    
  } else if (valP < 700) {
    analogWrite(LED_R, 255);
    analogWrite(LED_G, res);
    analogWrite(LED_B, 255);
  } else {
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, res);
  }

  delay(500);
}
