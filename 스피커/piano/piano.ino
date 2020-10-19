#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_G 392
#define NOTE_A 440

const int SPEAKER = 9;
const int BTN_C = 7;
const int BTN_D = 6;
const int BTN_E = 5;
const int BTN_G = 4;
const int BTN_A = 3;

char note;
int count = 0; // 2bytes
unsigned int countUnsignedInt = 0; // 2bytes
unsigned long countUnsignedLong = 0; // 4bytes 

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT); // tone() 디폴트로 output 설정해줘서 필요없긴함
  pinMode(BTN_C, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);
  pinMode(BTN_E, INPUT_PULLUP);
  pinMode(BTN_G, INPUT_PULLUP);
  pinMode(BTN_A, INPUT_PULLUP);
}

void loop() {
  count = 0;
  countUnsignedInt = 0;
  countUnsignedLong = 0; 
  
  while(digitalRead(BTN_C) == LOW){
    tone(SPEAKER, NOTE_C);
    note = 'C';
    count++;
    countUnsignedInt++;
    countUnsignedLong++;
  }
  while(digitalRead(BTN_D) == LOW){
    tone(SPEAKER, NOTE_D);
    note = 'D';
    count++;
    countUnsignedInt++;
    countUnsignedLong++;
  }
  while(digitalRead(BTN_E) == LOW){
    tone(SPEAKER, NOTE_E);
    note = 'E';
    count++;
    countUnsignedInt++;
    countUnsignedLong++;
  }
  while(digitalRead(BTN_G) == LOW){
    tone(SPEAKER, NOTE_G);
    note = 'G';
    count++;
    countUnsignedInt++;
    countUnsignedLong++;
  }
  while(digitalRead(BTN_A) == LOW){
    tone(SPEAKER, NOTE_A);
    note = 'A';
    count++;
    countUnsignedInt++;
    countUnsignedLong++;
  }
  
  noTone(SPEAKER);

  if (count != 0) {
    Serial.print("Note : ");
    Serial.print(note);
    Serial.print(", Times : ");
    Serial.print(count);
    Serial.print(" / ");
    Serial.print(countUnsignedInt);
    Serial.print(" / ");
    Serial.println(countUnsignedLong);
  }
}
