const int BUTTON_INT =0; //Interrupt 0 (pin 2 on the Uno)
const int RED =11;
const int GREEN =10;
const int BLUE =9;

volatile int selectedLED = RED;

void setup() {
  pinMode (RED, OUTPUT);
  pinMode (GREEN, OUTPUT);
  pinMode (BLUE, OUTPUT);
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);

  //The pin is inverted, so we want to look at the rising edge
  attachInterrupt(BUTTON_INT, swap, RISING);
}

void loop() {
  for (int i = 0; i<256; i++) {
    analogWrite(selectedLED, i);
    delay(10);
    }
    for (int i = 255; i>= 0; i--) {
    analogWrite(selectedLED, i);
    delay(10);
  }
}

void swap() {
  analogWrite(selectedLED, 255);
  if (selectedLED == GREEN)
    selectedLED = RED;
  else if (selectedLED == RED)
    selectedLED = BLUE;
  else if (selectedLED == BLUE)
    selectedLED = GREEN;
}
