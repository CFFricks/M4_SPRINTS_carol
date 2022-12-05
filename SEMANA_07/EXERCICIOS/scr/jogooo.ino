#define btn1 9
#define btn2 16
#define LEDAzul 39
#define LEDVerde 11
bool pre = false;
// ponto1 = 0;
// ponto2 = 0;

void p1(){
  if(pre == false){
  Serial.println("player 1 selecionado");
  digitalWrite(LEDAzul, HIGH);
  digitalWrite(LEDVerde, LOW);
  pre = true;

  }
  }


void p2(){
  if(pre == false){
  Serial.println("player 2 selecionado");
  digitalWrite(LEDVerde, HIGH);
  digitalWrite(LEDAzul, LOW);
  pre = true;
  }
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  attachInterrupt(btn1, p1, RISING);
  attachInterrupt(btn2, p2, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  pre = false;

}
