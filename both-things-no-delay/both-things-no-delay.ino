int lastTimeItHappened = 0;              // The clock time in millis()
int howLongItsBeen;                         // A calculated value
const int ledPin = 13;
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int howLongToWait = 30;
int brightness = 0;
int fadeAmount = 5;
int buttonPin = 2;
int buttonPin2 = 4;
int ledPin2 = 3;

void setup() {
 pinMode (ledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);

if (buttonState == HIGH && buttonState2 == LOW) {
  Serial.println("vib only");
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

 if (buttonState2 == HIGH && buttonState == LOW) {
  Serial.println("both");
  analogWrite(ledPin2, brightness);
 howLongItsBeen = millis() - lastTimeItHappened;
 if ( howLongItsBeen >= howLongToWait ) {
   // do it (again)
   brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    }
    lastTimeItHappened = millis();
 }
 
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
else {
  // turn LED off:
  Serial.println("off");
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
}
}

