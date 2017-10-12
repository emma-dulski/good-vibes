// hardware pins
const int button1Pin = 2;        // input pin for switch 1
const int button2Pin = 4;        // input pin for switch 2
const int ledPin = 3;            // output pin for LED 
const int vibePin = 13;           // output pin for VIBE

// knobs
const int howLongToWaitLED = 30;  // how many millis() to wait between brightness changes
int fadeAmount = 5;               // how much to bump LED each change (note, changes sign)

// internal states
int brightness = 0;               // current LED brightness
int button1State = 0;             // variable for reading the pushbutton status
int button2State = 0;             
int lastTimeItHappenedLED = 0;    // time in millis() since last LED action
int lastTimeItHappenedVIBE = 0;   // time in millis() since last VIBE action
int howLongItsBeen;               // temp calculated value

bool bothON = false;               // make LED breath?
bool vibeON = false;              // make heart beat?

// setup all hardware
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(vibePin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  // read the state of the hardware buttons
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // interpret the button inputs and set the LED or VIBE as needed
  vibeON = (button1State == HIGH && button2State == LOW);
  bothON = (button2State == HIGH && button1State ==LOW);

  // ***** handle LED brightness *****
  if (bothON == true) {
   Serial.println("both");
    howLongItsBeen = millis() - lastTimeItHappenedLED;

    // time do adjust LED?
    if (howLongItsBeen >= howLongToWaitLED) {
      brightness = brightness + fadeAmount;
      // did we either top or bottom out? if so, reverse direction
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      // make sure we don't go over the 255 or 0, or we'll glitch for a moment
      brightness = min(brightness,255);
      brightness = max(brightness,0);
      lastTimeItHappenedLED = millis();
    } else {
      brightness = 0;
    }
    // set the new brightness
    analogWrite(ledPin, brightness);
    howLongItsBeen = millis() - lastTimeItHappenedVIBE;

  
  }

if (vibeON == true) {
Serial.println("vibe only");
}
  // ***** handle on/off vibe pin if needed *****
  if (vibeON == true || bothON == true) {
   
    howLongItsBeen = millis() - lastTimeItHappenedVIBE;

    // make the pin turn on and off in the heartbeat pattern
    if (howLongItsBeen < 80) {
      digitalWrite(vibePin, HIGH);
    } else {
      if (howLongItsBeen < 280) {
        digitalWrite(vibePin, LOW);
      } else {
        if (howLongItsBeen < 360) {
          digitalWrite(vibePin, HIGH);
        } else {
          if (howLongItsBeen < 1060) {
            digitalWrite(vibePin, LOW);
          } else {
            // vibe cycle done, so cycle back to start
            lastTimeItHappenedVIBE = millis();
          }
        }
      }
    }
  } else {
    Serial.println("off");
    // boring mode, no vibeing
    digitalWrite(vibePin, LOW);
  }
  
}

