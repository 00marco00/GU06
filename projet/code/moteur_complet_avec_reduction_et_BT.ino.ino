#include<SoftwareSerial.h>
#define RX 10 
#define TX 11
SoftwareSerial BT(TX,RX);
char state = 0;

char t = 1; //valeur recu par blutooth
char n = 0; //valeur recu par blutooth

int etat = 0;
int tps = 3000;//1700 = un toure de molette mais bt suis pas BT fonctio a partire de 3seconde

int pin2 = 7;
int pin3 = 8;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 2;
int pin8 = 3;
int pin9 = 9;


int pin12 = A0;
int pin13 = A1;

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
pinMode(pin12, OUTPUT);
pinMode(pin13, OUTPUT);

BT.begin(38400);
Serial.begin(9600);


}

void loop() {

//recupe du moteur q fqire tourner
  if (BT.available()>0){
    Serial.println(BT.read());
    if (BT.read() == '0'){
      Serial.println(BT.read());
      Serial.println("sssssssssssssssssssssss");
      t = 0;
    }
  }

// recup du sens de rotation du moteur 
 



//choisit quelle moteur doit tourner en fonction de la corde a accorder
if (n == 1){ pin2 = pin4; pin3 = pin5;}
if (n == 2){ pin2 = pin6; pin3 = pin7;}
if (n == 3){ pin2 = pin8; pin3 = pin9;}
if (n == 4){ }
if (n == 5){ pin2 = pin12; pin3 = pin13;}

if (etat == t){
  tps = tps/2;
  }

//fait tourner a ... pour ... la corde
if (t == 1){
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
etat = 1;
}

//fait tourner a ... pour ... la corde
if (t == 0){
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
etat = 2;
}

//laisse au moteur le temps de faire un tour
delay(tps);
}
