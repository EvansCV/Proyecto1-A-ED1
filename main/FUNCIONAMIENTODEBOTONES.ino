const int redPin1 = 16;
const int greenPin1 = 17;
const int bluePin1 = 18;

const int buttonPin1 = 43;  // Botón 1 (Rojo)
const int buttonPin2 = 45;  // Botón 2 (Verde)

// NO USAR PIN 44 -> NO FUNCIONA BIEN

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == LOW) {
    setColor(255, 0, 0);  // Rojo
    Serial.println("Rojo");
  }
  else if (buttonState2 == LOW) {
    setColor(0, 255, 0);  // Verde
    Serial.println("Verde");
  }
  else {
    setColor(0, 0, 0);  // Apagar LED
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin1, red);
  analogWrite(greenPin1, green);
  analogWrite(bluePin1, blue);
}
