//definindo os 
int LED1 = 19;
int LED2 = 14;
int LED3 = 21;
int LED4 = 13;
int botao1 = 48;
int botao2 = 40;
int buzzerPin = 11;
int Ldr = 15;
int binario[4];
int numeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int freqs[10000];
int x = 0;
int normalizacaoDoValor;

void setup() {
  //setup dos leds
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  //setup do buzzer
  pinMode(buzzerPin, OUTPUT);
  //setup dos botoes
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  //setup do ldr
  pinMode(Ldr, INPUT);

  Serial.begin(9600);
}

//função que converte o numero decimal para o binario
void converte_binario(int valor){
  int i = 0;
  while (i != 4)
  {
    binario[i] = valor % 2;
    valor = valor / 2;
    i++;
  }
}
//separa o valor lido no ldr em intervalos, para termos apenas 15
int normalizacao(int atualValor)
{
  int novoValor = (atualValor * 15) / 2670;

  return novoValor;  
}

void tom(char buzzerPin, int freq, int tempo){
  float duracao = 1000.0/freq;
  for (int i = 0; i < tempo/(duracao); i++){
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(duracao*500);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(duracao*500);
  }
}
//um tom para cada numero
void musicaBinaria(int valorSensor) {

  switch(valorSensor) {
    case 1:
      tom(buzzerPin, 500, 500);
    break;
    case 2:
      tom(buzzerPin, 700, 500);
    break;
    case 3:
      tom(buzzerPin, 900, 500);
    break;
    case 4:
      tom(buzzerPin, 1100, 500);
    break;
    case 5:
      tom(buzzerPin, 1300, 500);
    break;
    case 6:
      tom(buzzerPin, 1500, 500);
    break;
    case 7:
      tom(buzzerPin, 1700, 500);
    break;
    case 8:
      tom(buzzerPin, 1900, 500);
    break;
    case 9:
      tom(buzzerPin, 2100, 500);
    break;
    case 10:
      tom(buzzerPin, 2400, 500);
    break;
    case 11:
      tom(buzzerPin, 2600, 500);
    break;
    case 12:
      tom(buzzerPin, 2800, 500);
    break;
    case 13:
      tom(buzzerPin, 3000, 500);
    break;
    case 14:
      tom(buzzerPin, 3200, 500);
    break;
    case 15:
      tom(buzzerPin, 3400, 500);
    break;

  }
}

void acendeLed()
{
  digitalWrite(LED1, binario[3]);
  digitalWrite(LED2, binario[2]);
  digitalWrite(LED3, binario[1]);
  digitalWrite(LED4, binario[0]);
  
  delay(200);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  binario[0] = 0;
  binario[1] = 0;
  binario[2] = 0;
  binario[3] = 0;
}

void loop() {
  int button1Input = digitalRead(botao1);
  int button2Input = digitalRead(botao2);

  if (button1Input == 0)
  {
    if (x < 10)
    {
      Serial.println("gravado");
      int ldrValue = analogRead(Ldr);
      normalizacaoDoValor = normalizacao(ldrValue);

      numeros[x] = normalizacaoDoValor;

      x += 1;

      converte_binario(normalizacaoDoValor);

      musicaBinaria(normalizacaoDoValor);

      acendeLed();
    }
    else
    {
      tom(buzzerPin, 5000, 500);
      delay(250);
      tom(buzzerPin, 5000, 500);
      delay(250);
      tom(buzzerPin, 5000, 500);
    }
  }

  if (button2Input == 0)
  {
    Serial.println("reproduzido");
    rodar();
  }
}

void rodar()
{
  for (int i = 0; i < sizeof(numeros)/4; i ++)
  {
    musicaBinaria(numeros[i]);
    converte_binario(numeros[i]);
    acendeLed();
  }

  x = 0;
}