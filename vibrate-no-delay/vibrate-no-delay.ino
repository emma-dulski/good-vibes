int howLongToWait = 200;                 // Wait this many millis()
int howLongToWait2 = 80;
int lastTimeItHappened = 0;              // The clock time in millis()
int howLongItsBeen;                         // A calculated value
const int ledPin = 13;



void setup () {
pinMode (ledPin, OUTPUT);
Serial.begin(9600);
}

void loop () {
// digitalWrite(ledPin, HIGH);
 howLongItsBeen = millis() - lastTimeItHappened;
 if ( howLongItsBeen >= howLongToWait ) {
 analogWrite( 13, 255 ); 
 }
 else if (howLongItsBeen >= howLongToWait2 ) {
  Serial.println(howLongItsBeen);
 digitalWrite( ledPin, LOW );
 lastTimeItHappened = millis();
 }
}
