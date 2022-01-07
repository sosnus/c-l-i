//String message = "";         // a String to hold incoming data
char message[] = {"rgb(126, 127, 128)"};
bool stringComplete = false;  // whether the string is complete
char * ptr;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
//  message.reserve(200);
}

void loop() {

  if (stringComplete) {
    Serial.print("New: ");
    Serial.println(message);
    rgbToPwm();
    // clear the string:
    
//    message = "";
    stringComplete = false;
  }
  

  // put your main code here, to run repeatedly:

}

void serialEvent() {
  int i = 0;
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    message[i]= inChar;
    i++;
//    message += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void rgbToPwm(){

//          char message[] = {"rgb(126, 127, 128)"};
//        char * ptr;
        ptr = strtok(message, "("); //move past (
        ptr = strtok(NULL, ",");  //next comma is red
        byte RED = atoi(ptr);
        Serial.print("SET LEDS TO....");
        Serial.println(RED);
        ptr = strtok(NULL, ",");  //next comma is green
        byte GREEN = atoi(ptr);
        Serial.println(GREEN);
        ptr = strtok(NULL, ",");  //next comma is blue
        byte BLUE = atoi(ptr);
        Serial.println(BLUE);
        delay(2000);
  
}
