#include <iostream>
#include <algorithm>
using std::cout;
using std::swap;

template <typename T>
int particionar (T *v, int i, int p, int f) {
  // algoritmo de Hoare 
  int left = i+1;
  int right = f;
  swap(v[p], v[0]);
  p = 0;
  while (left <= f && left <= right) {
    if(v[left] >= v[p]) { // setinha esquerda
      while(v[right] > v[p] && right > left) { // setinha direita
        right--;
      }
      swap(v[left], v[right]); // troca os valores
      right--;
    } left++;
  } 

  // colocando pivô no lugar correto
  left = i + 1;
  while(v[left] < v[p] && left <= f) {
    left++;
  } swap(v[left-1], v[p]);
  return left - 1;
}

template <typename T>
void quickSort (T *v, int n) {
  if(n <= 0) return;
  int pivot = particionar(v, 0, n/2, n);
  quickSort(v, pivot);
  pivot = particionar(v, pivot, (pivot+n)/2, n);
  quickSort(v, pivot);
}

int main() {
  int valores[] = {2,6,6,10,11,23,985,7,2,3,0};
  quickSort(valores, 7);

  for(int i = 0; i < 8; i++) {
    cout << valores[i] << ' ';
  }
  return 0;
}
