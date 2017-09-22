int old;

void setup() {
  // Serial.begin (9600)
  //
}

void loop() {
 
  boolean button;
  button = digitalRead(2);
// Serial.printIn(button);
// delay(100);

//if(button == HIGH && button != old){
//  Serial.printIN("Switch Toggled");
//}
  if (button == HIGH){

    analogWrite( 3, 255 );
    delay(80);

    analogWrite( 3 , 0 );
    delay(200);

    analogWrite( 3 , 245 );
    delay(80);

    analogWrite( 3 , 0 );
    delay(200)
  }

