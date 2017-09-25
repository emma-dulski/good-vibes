
int howLongToWait = 30;                 // Wait this many millis()
int lastTimeItHappened = 0;              // The clock time in millis()
int howLongItsBeen;                         // A calculated value
const int ledPin = 13;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
pinMode (ledPin, OUTPUT);
}



void loop () {
 analogWrite(ledPin, brightness);
 howLongItsBeen = millis() - lastTimeItHappened;
 if ( howLongItsBeen >= howLongToWait ) {
   // do it (again)
   brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    }
    lastTimeItHappened = millis();
 }
}




