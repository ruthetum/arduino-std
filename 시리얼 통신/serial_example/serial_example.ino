void setup() {
 Serial.begin(9600);
 
 Serial.println(78); // 78
 Serial.println("78"); // 78
 Serial.println(1.23); // 1.23
 Serial.println(1.23456); // 1.23
 Serial.println(1.56789); // 1.57
 Serial.println("1.23456"); // 1.23456
//  Serial.println(N); // error
 Serial.println('N'); // N
 Serial.println("N"); // N
 Serial.println('NN'); // 20046 (error)
 Serial.println("NN"); // NN

 Serial.println("\n=============\n");
 Serial.println(78); // 78
 Serial.println(78, BIN); // 1001110
 Serial.println(78, OCT); // 116
 Serial.println(78, DEC); // 78
 Serial.println(78, HEX); // 4E
 Serial.println(1.23456, 0); // 1
 Serial.println(1.23456, 2); // 1.23
 Serial.println(1.23456, 4); // 1.2346
}

void loop() {
  
}
