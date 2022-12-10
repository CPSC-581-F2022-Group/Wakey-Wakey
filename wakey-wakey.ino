#define trigPin 12
#define echoPin 13
int Buzzer = 2; //Connect buzzer to pin 2
int ledPin= 6; //Connect LED to pin 6
int buttonPin = 8; //Connect button to pin 8
int duration, distance; //Measures the distance and time taken 
int wait = 1;
int buttonState = 0;
	
//Define the output and input objects(devices)
void setup() {
  Serial.begin (9600); 
  pinMode(Buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, LOW);
  delay(10000); //Ten second delay to sync with robots
}

void loop() {
    buttonState = digitalRead(buttonPin); //Get the state of the button
    Serial.println(buttonState); //Show the state of pushbutton on serial monitor

    //Check if the pushbutton is pressed
    if (buttonState == 1) {
      noTone(Buzzer); //Turn buzzer off
      digitalWrite(ledPin, LOW); //Turn LEDs off
      wait = 0;
    }
    delay(1000); //Added delay so we can see the output of button
  
	if(wait == 1){
    	tone(Buzzer, 1000); //Play tone 
    	digitalWrite(ledPin,HIGH); //Turn on LEDs
    	digitalWrite(Buzzer,HIGH); //Turn on buzzer
	}  
}
