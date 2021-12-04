int Signal_GBF = A0; // Signal Analogique

void setup() {

// Configure le port série pour l'exemple
Serial.begin(9600);

// Met la broche de signal venant du GBF en entrée
pinMode(Signal_GBF, INPUT);
}

void loop() {

// Mesure la durée de l'impulsion haute (timeout par défaut de 1s)
noInterrupts();
unsigned long etat_haut = pulseIn(Signal_GBF, HIGH);
interrupts();

// Mesure la durée de l'impulsion basse (timeout par défaut de 1s)
noInterrupts();
unsigned long etat_bas = pulseIn(Signal_GBF, LOW);
interrupts();
delay(1000);

// Calcul de la periode = etat haut + etat bas
long periode = (etat_bas + etat_haut);
// Calcul de la frequence = 1 / periode
long frequence = (1/ (periode*0.000001));
Serial.println("Duree etat haut : ");
Serial.print(etat_haut);
Serial.println("");
Serial.println("Duree etat bas : ");
Serial.print(etat_bas);
Serial.println("");
Serial.println("Periode : ");
Serial.print(periode);
Serial.println("");
Serial.println("Frequence : ");
Serial.print(frequence);
Serial.println(" Hz");
Serial.println("");


}
