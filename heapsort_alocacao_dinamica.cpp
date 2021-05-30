#include <iostream>
#include <math.h>
using std::cin;
using std::cout;

// fesq(i) = 2*i + 1
// fdir(i) = 2*i + 2
// pai(i) = (i-1)/2

template <typename T>
int descer(T *v, int n, int i) {
  int left_child, right_child, largest, aux = 0;
  bool flag = true;
  while(flag){
    largest = i; // the largest it's dad
    left_child = 2*i + 1; // left child
    right_child = left_child+1; // right child
    if(left_child < n && v[left_child] > v[i] && v[left_child] >= v[right_child]) largest = left_child; // if left child exists and he its largest tha him dad, now, left child is the largest
    if(right_child < n && v[right_child] > v[i] && v[right_child] >= v[left_child]) largest = right_child;
    aux = v[i];       
    v[i] = v[largest];
    v[largest] = aux;
    flag = (i != largest);
		i = largest;
  }
 }

template <typename T>
void heapsort (T *v, int n) {
  int levels = log2(n); // number of levels in the tree, n = number of nodes total
  int n_leaf_nodes = pow(2, (levels-1) + 1) - 1; // number of non- leaf nodes.
  for(int i = n_leaf_nodes - 1; i >= 0; i--) {
    descer(v, n, i);
  }
}

template <typename T>
T *mudarValores(int currentSize, int *newSize, T *currentArray) {
  (*newSize) = (*newSize)*2;
  T *newArray = new T[(*newSize)]; 
  if(newArray == nullptr) return 0;
  for(int i = 0; i < currentSize; i++) newArray[i] = currentArray[i];
  delete [] currentArray;
  return newArray;
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
  heapsort(vetor, 7);
  cout << "Valores ordenados: " << '\n';
  cout << '{';
  for(int i = 0; i < 7; i++) {
    if(i != 0) cout << ", ";
    cout << vetor[i];
  } cout << '}';
}