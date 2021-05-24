#include <iostream>
using std::cin;
using std::cout;

int *mudarValores(int currentSize, int *newSize, int currentArray[]) {
  (*newSize) = (*newSize)*2;
  int *newArray = new int[(*newSize)]; 
  if(newArray == nullptr) {
    cout << "Falha na alocação!" << '\n';
    return 0;
  } else {
    for(int i = 0; i < currentSize; i++) newArray[i] = currentArray[i];
    delete [] currentArray;
    return newArray;
  }
}

int main() {
  int valor; // valor digitado pelo usuário
  int tam = 1; // tamanho do vetor

  int *p_tam = &tam;
  int *vetor = new int[tam]; 

  int i = 0;

  while (valor != 0)
  {
    cin >> valor;
    if(i >= tam) {
      vetor = mudarValores(tam, p_tam, vetor);
      vetor[i] = valor;
    } else {
      vetor[i] = valor;
    } 
    i++;
  }
  
  for(int i = 0; i < tam; i++) cout << "valor[" << i << "]: " << vetor[i] << '\n';
}