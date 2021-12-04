float long fq = 0;
float long f1 = 329,63;
float long f1 = 246,94;
float long f1 = 196,00;
float long f1 = 146,83;
float long f1 = 110,00;
float long f1 = 82,41;
int n = 0;
//char p = ""
ledV = 3;
ledRD =2;
ledRG = 4;

void setup() {

  pinMode(ledV, OUTPUT);
  pinMode(ledRG, OUTPUT);
  pinMode(ledRD, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //pour pouvoir afficher la note accordé sur l'écran plus tard
  //if (n == 0) {p = ""};
  //if (n == 1) {p = ""};
  //if (n == 2) {p = ""};
  //if (n == 3) {p = ""};
  //if (n == 4) {p = ""};
  //if (n == 5) {p = ""};

  //corde arccordé
  if (fq < fn - 10 && fq > fn + 10){
    digitalWrite(ledV, LOW);
    n = n + 1;
    Serial.println("OK");
    }

  //détendre la corde 
  else if (fq > fn + 10){
      digitalWrite(ledRD, LOW);
      Serial.println("Trop haut");
    }

  //tendre la corde
  else if (fq < fn - 10){
      digitalWrite(ledRG, LOW);
      Serial.println("Trop Bas");
    }
  delay (3000);
  digitalWrite(ledV, HIGH);
  digitalWrite(ledRG, HIGH);
  digitalWrite(ledRD, HIGH);
}
