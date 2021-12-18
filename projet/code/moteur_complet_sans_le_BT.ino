int t = 1 //valeur recu par blutooth
int n = 0//valeur recu par blutooth

int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int pin12 = 12;
int pin13 = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);
pinMode(pin7, OUTPUT);
pinMode(pin8, OUTPUT);
pinMode(pin9, OUTPUT);
pinMode(pin10, OUTPUT);
pinMode(pin11, OUTPUT);
pinMode(pin12, OUTPUT);
pinMode(pin13, OUTPUT);
}

void loop() {
//choisit quelle moteur doit tourner en fonction de la corde a accorder
if (n == 0){ pin = pin2; pin1 = pin3;}
if (n == 1){ pin = pin4; pin1 = pin5;}
if (n == 2){ pin = pin6; pin1 = pin7;}
if (n == 3){ pin = pin8; pin1 = pin9;}
if (n == 4){ pin = pin10; pin1 = pin11;}
if (n == 5){ pin = pin12; pin1 = pin13;}

//fait tourner a ... pour ... la corde
if (t == 1){
digitalWrite(pin,LOW);
digitalWrite(pin1,HIGH);
}

//fait tourner a ... pour ... la corde
if (t == 2){
digitalWrite(pin,HIGH);
digitalWrite(pin1,LOW);
}

//laisse au moteur le temps de faire un tour
delay(1700);
}
