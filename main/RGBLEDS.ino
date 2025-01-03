// Pines para el primer LED RGB
const int redPin1 = 16;
const int greenPin1 = 17;
const int bluePin1 = 18;

// Pines para el segundo LED RGB
const int redPin2 = 19;
const int greenPin2 = 20;
const int bluePin2 = 21;

//CONTINUAR CON LO DE LOS PINES HASTA LLEGAR A 6 (SEGUIR EN EL ORDEN)

void setup() {
  // Configuramos los pines del primer LED como salidas
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);

  // Configuramos los pines del segundo LED como salidas
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
}

void loop() {
  // Ciclo de colores
  // Rojo
  setColor(redPin1, greenPin1, bluePin1, 255, 0, 0);  // Primer LED en rojo
  setColor(redPin2, greenPin2, bluePin2, 0, 0, 0);    // Segundo LED Blanco
  delay(2000);
  
  setColor(redPin2, greenPin2, bluePin2, 255, 0, 0);  // Segundo LED en rojo
  setColor(redPin1, greenPin1, bluePin1, 0, 0, 0);    // Primer LED Blanco
  delay(2000);
}

// Función para establecer el color de cada LED RGB
void setColor(int redPin, int greenPin, int bluePin, int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}