float fq = 0;
float f = 0;
float f0 = 329.63;
float f1 = 246.94;
float f2 = 196.00;
float f3 = 146.83;
float f4 = 110.00;
float f5 = 82.41;
int n = 0;
//char p = ""
int ledV = 3;
int ledRD =2;
int ledRG = 4;
int Signal_GBF = A0;

void setup() {

  pinMode(ledV, OUTPUT);
  pinMode(ledRG, OUTPUT);
  pinMode(ledRD, OUTPUT);
  Serial.begin(9600);
  pinMode(Signal_GBF, INPUT);
}

void loop() {
  //pour pouvoir afficher la note accordé sur l'écran plus tard plus definire les frequence de référence
  if (n == 0) {f = f0;}
  if (n == 1) {f = f1;}
  if (n == 2) {f = f2;}
  if (n == 3) {f = f3;}
  if (n == 4) {f = f4;}
  if (n == 5) {f = f5;}

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
  fq = (1/ (periode*0.000001));

  Serial.print(fq);
  Serial.println(" Hz");
  Serial.println("");

  //corde arccordé
  if (fq > f - 10 && fq < f + 10){
    digitalWrite(ledV, HIGH);
    n = n + 1;
    Serial.println("OK");
    }

  //détendre la corde 
  else if (fq > f + 10){
      digitalWrite(ledRD, HIGH);
      Serial.println("Trop haut");
    }

  //tendre la corde
  else if (fq < f - 10){
      digitalWrite(ledRG, HIGH);
      Serial.println("Trop Bas");
    }
  delay (3000);
  digitalWrite(ledV, LOW);
  digitalWrite(ledRG, LOW);
  digitalWrite(ledRD, LOW);
}
