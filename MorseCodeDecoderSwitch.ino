//dots are 100ms long
int dotLength = 100;

//dashes are 3000ms long
int dashLength = 300;

int buttonOne = 3;
int buttonTwo = 4;

boolean buttonTwoDown = false;

long buttonTimer = 0; //to time how long the button was pressed.

boolean buttonActive = false;
boolean longPressActive = false;

//string to hold what is currently being typed
String currentTyping;

//string to hold letter typed
String letterTyped;

//word typed
String wordTyped = "";

//ASCII letter
String asciiLetter;

void setup() {
  // put your setup code here, to run once:
    pinMode(buttonOne, INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonOne) == HIGH) {
    if (buttonActive == false) {
      buttonActive = true;
      buttonTimer = millis();
    }

    if ((millis() - buttonTimer > dashLength) && (longPressActive == false)) {
      longPressActive = true;
      
      currentTyping += ("-");
      Serial.println("Typed: " +currentTyping);
    }
    
  } else {
    if (buttonActive == true) {
      if (longPressActive == true) {
        longPressActive = false;
      } else {

        currentTyping += (".");
        Serial.println("Typed: " +currentTyping);
      }
      buttonActive = false;
    }
  }
  if(digitalRead(buttonTwo) == HIGH){
    if (buttonTwoDown == false){
      buttonTwoDown = true;
      letterTyped = currentTyping;
      currentTyping = "";
      Serial.println("Letter typed: " + letterTyped);
  
      if(letterTyped == ".-"){
        asciiLetter = "A";
      }else if(letterTyped == "-..."){
        asciiLetter = "B";
      }else if(letterTyped == "-.-."){
        asciiLetter = "C";
      }else if(letterTyped == "-.."){
        asciiLetter = "D";
      }else if(letterTyped == "."){
        asciiLetter = "E";
      }else if(letterTyped == "..-."){
        asciiLetter = "F";
      }else if(letterTyped == "--."){
        asciiLetter = "G";
      }else if(letterTyped == "...."){
        asciiLetter = "H";
      }else if(letterTyped == ".."){
        asciiLetter = "I";
      }else if(letterTyped == ".---"){
        asciiLetter = "J";
      }else if(letterTyped == "-.-"){
        asciiLetter = "K";
      }else if(letterTyped == ".-.."){
        asciiLetter = "L";
      }else if(letterTyped == "--"){
        asciiLetter = "M";
      }else if(letterTyped == "-."){
        asciiLetter = "N";
      }else if(letterTyped == "---"){
        asciiLetter = "O";
      }else if(letterTyped == ".--."){
        asciiLetter = "P";
      }else if(letterTyped == "--.-"){
        asciiLetter = "Q";
      }else if(letterTyped == ".-."){
        asciiLetter = "R";
      }else if(letterTyped == "..."){
        asciiLetter = "S";
      }else if(letterTyped == "-"){
        asciiLetter = "T";
      }else if(letterTyped == "..-"){
        asciiLetter = "U";
      }else if(letterTyped == "...-"){
        asciiLetter = "V";
      }else if(letterTyped == ".--"){
        asciiLetter = "W";
      }else if(letterTyped == "-..-"){
        asciiLetter = "X";
      }else if(letterTyped == "-.--"){
        asciiLetter = "Y";
      }else if(letterTyped == "--.."){
        asciiLetter = "Z";
      }else if(letterTyped == "......"){
        asciiLetter = " ";
      }else{
        asciiLetter = "";
      }
      Serial.println("You typed: " + asciiLetter);
      wordTyped += asciiLetter;
      Serial.println("Word typed: " + wordTyped);
      asciiLetter = "";
      letterTyped = "";
    }
  }
  if(digitalRead(buttonTwo) == LOW){
    buttonTwoDown = false;
  }
}

