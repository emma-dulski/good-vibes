int lastTimeItHappened = 0;              // The clock time in millis()
int howLongItsBeen;                         // A calculated value
const int ledPin = 13;
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int howLongToWait = 30;
int brightness = 0;
int fadeAmount = 5;

void setup() {
 pinMode (ledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);

if (buttonState == HIGH && buttonState2 == LOW) {
howLongItsBeen = millis() - lastTimeItHappened;
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

else if (buttonState2 == HIGH && buttonState == HIGH ) {
  
}

