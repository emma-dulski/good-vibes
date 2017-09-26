int howLongToWait = 200;                 // Wait this many millis()
int howLongToWait2 = 80;
int howLongToWait3 = 700;
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
// if ( howLongItsBeen >= howLongToWait ) {
// digitalWrite( ledPin, LOW ); 
// }
// else if (howLongItsBeen >= howLongToWait2 ) {
//  Serial.println(howLongItsBeen);
// digitalWrite( ledPin, HIGH );
// lastTimeItHappened = millis();

if (0 <= howLongItsBeen && howLongItsBeen <= 80){
digitalWrite( ledPin, HIGH);}

if (80 <= howLongItsBeen && howLongItsBeen<= 280){
digitalWrite(ledPin, LOW);}

if (280 <= howLongItsBeen && howLongItsBeen<= 360){
digitalWrite(ledPin, HIGH);}

if (360 <= howLongItsBeen && howLongItsBeen<= 1060){
digitalWrite(ledPin, LOW);}

if (howLongItsBeen >= 1060){
lastTimeItHappened = millis ();}

 }

