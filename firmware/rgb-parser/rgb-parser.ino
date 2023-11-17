//char message[] = {"rgb(126, 127, 128)"};
String inputString = "";
bool stringComplete = false;  // whether the string is complete
char * ptr;
const int ledr = 9;
const int ledg = 10;
const int ledb = 11;
//int rgbval[3] = [0,0,0];


void setup() {
  Serial.begin(9600);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
}

void loop() {
  if (stringComplete) {
    Serial.print("New: ");
    Serial.println(inputString);
    rgbToPwm();
    stringComplete = false;
  }
}

void serialEvent() {
  int i = 0;
  while (Serial.available()) {
    Serial.print("New msg in buff: ");
    inputString = Serial.readString();
    Serial.println(inputString);
    rgbToPwm();

  }
}

void rgbToPwm() {
  String r = inputString.substring(4, 7);

  analogWrite(ledr, inputString.substring(4, 7).toInt());
  analogWrite(ledg, inputString.substring(9, 12).toInt());
  analogWrite(ledb, inputString.substring(14, 17).toInt());
  Serial.println(r);
}