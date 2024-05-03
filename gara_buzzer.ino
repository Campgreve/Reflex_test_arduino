const int pinPA=13;
const int pinPB=0;
const int pinPstart=8;
const int pinBuzzer=9;
const int pinLA=10;
const int pinLB=6;
const int pinLverde=7;

bool PA;
bool PB;
bool Pstart;
int totWinA=0;
int totWinB=0;
int nota;

void setup(){
  pinMode(pinPA, INPUT_PULLUP);
  pinMode(pinPB, INPUT_PULLUP);
  pinMode(pinPstart, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLA, OUTPUT);
  pinMode(pinLB, OUTPUT);
  pinMode(pinLverde, OUTPUT);

  randomSeed(analogRead(0));

  Serial.begin(9600);
}

void loop(){
  digitalWrite(pinLverde, HIGH);
do{
  Pstart = digitalRead(pinPstart);
} while(Pstart==1);
  
  
  digitalWrite(pinLverde, HIGH);
  delay(random(3000, 8000));
  PA = digitalRead(pinPA);
  PB = digitalRead(pinPB);
  tone (pinBuzzer, 262);
  digitalWrite(pinLverde, HIGH);

   if(PA==0 || PB==0) {
    if(PA==0 && PB==1) vincitore(pinLB);
    if(PA==1 && PB==0) vincitore(pinLA);
    if(PA==0 && PB==0) Serial.println("Gara non valida"); 
}
else {
  do{
    PA = digitalRead(pinPA);
    PB = digitalRead(pinPB);
  }while(PA && PB);

  if(PA==0) vincitore(pinLA);
  if(PB==0) vincitore(pinLB);
 }

  noTone (pinBuzzer);
}


void vincitore (int winner){

  digitalWrite(pinLverde, LOW);

  if(winner==pinLA){
    Serial.println("Ha vinto A");
    totWinA++;
    nota==440;
  }
  if(winner==pinLB){
    Serial.println("Ha vinto B");
    totWinA++;
    nota=587;    
  }
  Serial.print("Punti totali A:");
  Serial.print(totWinA);
  Serial.print("   B:");
  Serial.print(totWinB);


  for(int cont=1; cont<=5; cont++){
    tone(pinBuzzer, nota);
    digitalWrite(winner, HIGH);
    delay(500);
    noTone (pinBuzzer);
    digitalWrite(winner, LOW);
    delay(500);
  }
}
