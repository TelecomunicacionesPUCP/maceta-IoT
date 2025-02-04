/*
 * Taller IoT PUCP Verano 2025
 * Ingeniería de las Telecomunicaciones 
 * Clase Sensores: LDR + LED
 * Actividad: Detectar oscuridad para prender un LED
 */

//Definiendo variables constantes
const int ledPin = 5; //Se define el pin a utilizar del nodeMCU, en este caso será el pin D1 (GPIO 5)
const int ldrPin = A0; //Se define la entrada analógica del nodeMCU que va conectado al LDR

void setup() {

Serial.begin(9600); //Se inicializa la comunicación serial

pinMode(ledPin, OUTPUT); //Se define el pin D1 como salida
pinMode(ldrPin, INPUT); //Se define el pin A0 como entrada

}

void loop() {

int ldrStatus = analogRead(ldrPin); //Valor analógico entre 0 a 1023

  if (ldrStatus <= 900) {
  digitalWrite(ledPin, HIGH); //Si el valor de la variable ldrStatus es menor o igual a 900, entonces el LED se prende
  Serial.print(ldrStatus); //Se imprime el valor del voltaje
  Serial.println(" : LDR a oscuras, entonces el LED se enciende");
  delay(5000);
  }

  else {
  digitalWrite(ledPin, LOW); //Si el valor de la variable ldrStatus es mayor a 900, entonces el LED se apaga
  Serial.print(ldrStatus);
  Serial.println(" : LDR con luz, entonces el LED se apaga");
  delay(5000);
  }

}
