char message[] = {"rgb(126, 127, 128)"};
bool stringComplete = false;  // whether the string is complete
char * ptr;


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (stringComplete) {
    Serial.print("New: ");
    Serial.println(message);
    rgbToPwm();
    stringComplete = false;
  }
}

void serialEvent() {
  int i = 0;
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    message[i]= inChar;
    ++i;
    Serial.print(inChar);

    if (inChar == '\n') {
      stringComplete = true;
    Serial.print("New msg in buff: ");
    Serial.println(message);
    }
  }
}

void printPtr()
{
Serial.print("ptr=");
Serial.println(ptr);

}

void rgbToPwm(){
         char message[] = {str()};
       char * ptr;
printPtr();
        ptr = strtok(message, "("); //move past (
printPtr();
        ptr = strtok(NULL, ",");  //next comma is red
        byte RED = atoi(ptr);
printPtr();
        Serial.println("SET LEDS TO....");
        Serial.println(RED);
        ptr = strtok(NULL, ",");  //next comma is green
printPtr();
        byte GREEN = atoi(ptr);
        Serial.println(GREEN);
        ptr = strtok(NULL, ",");  //next comma is blue
        byte BLUE = atoi(ptr);
        Serial.println(BLUE);
        
// strncpy(message, "iqbal", sizeof(a) - 1);
        // for(int i = 0; i >)
        // delay(2000);
  
}
