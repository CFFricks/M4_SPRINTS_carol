#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ajeita a medida percentualmente entre dois valores
float converteSensor(int min, int max, int medida) {
  float resultado;
  resultado = (medida - min) / (max - min);
  return resultado;
}

//leitura do sensor, para receber o numero digitado
float Leitura() {
  int valor = 0;
  cin >> valor;
  return valor;
}

//armazena o valor inserido
int InsereVetor(int elemento, int valorMax, int lastPos, int *Vetor) {
  if (lastPos < valorMax - 1) {
    Vetor[lastPos + 1] = elemento;
  } else {
    cout << "Valor maximo" << valorMax
         << " Ultima posição mais um: " << lastPos + 1 << endl;
  }
  return lastPos + 1;
}

//qual distancia o robo vai e quantas "casas" ele vai
void MaiorDirecao(int *vetor, int maiorDirecao) {
  string posicoes[4] = {"Direita", "Esquerda", "Frente", "Tras"};
  string maiorPosicao;
  int maior = *vetor;
  for (int i = 0; i < 4; i++) {
    if (vetor[i] > maiorDirecao) {
      maiorDirecao = vetor[i];
      maiorPosicao = posicoes[i];
    }
  }
  cout << "Esta se movendo para: " << maiorPosicao << endl
       << "Distância: " << maiorDirecao << endl;
}

// booleano para ver se vai continuar a funcao ou nao
int leComando() {
  bool condicao = true;
  cout << "Para parar pressione 0" << endl;
  cin >> condicao;
  if (condicao == 0) {
    cout << "Acabou o loop!" << endl;
  }
  return condicao;
}
//teste do prof andre:
int dirige(int *v, int maxv) {
  int maxVetor = maxv;
  int *vetorMov = v;
  int posAtualVetor = 0;
  int dirigindo = 1;
  while (dirigindo) {
    cout << "Digite o valor para ser percorrido pelo lado direito: " << endl;
    int medida = Leitura();
    medida = converteSensor(0, 830, medida);
    posAtualVetor = InsereVetor(medida, maxVetor, posAtualVetor, vetorMov);

    cout << "Digite o valor para ser percorrido pelo lado esquerdo: " << endl;
    medida = Leitura();
    medida = converteSensor(0, 830, medida);
    posAtualVetor = InsereVetor(medida, maxVetor, posAtualVetor, vetorMov);

    cout << "Digite o valor para ser percorrido para cima " << endl;
    medida = Leitura();
    medida = converteSensor(0, 830, medida);
    posAtualVetor = InsereVetor(medida, maxVetor, posAtualVetor, vetorMov);

    cout << "Digite o valor para ser percorrido para baixo" << endl;
    medida = Leitura();
    medida = converteSensor(0, 830, medida);
    posAtualVetor = InsereVetor(medida, maxVetor, posAtualVetor, vetorMov);

    dirigindo = leComando();
  }
  return posAtualVetor;
}

void percorre(int *v, int tamPercorrido) {
  int *vetorMov = v;
  int maiorDir = 0;

  for (int i = 0; i < tamPercorrido; i += 4) {
    MaiorDirecao(&(vetorMov[i]), maiorDir);
  }
}

int main(int argc, char **argv) {
  int maxVetor = 100;
  int vetorMov[400];
  int posAtualVet = 0;

  posAtualVet = dirige(vetorMov, maxVetor);
  percorre(vetorMov, posAtualVet);

  return 0;
}