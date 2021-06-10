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
  while(v[left] < v[p]) {
    left++;
  } swap(v[left-1], v[p]);
  return left - 1;


  /*
  // algoritmo de Lomuto
  for(int j = i; j <= f; j++) {
    if(v[j] <= v[p] && j != p) {
        if(p == left && p+1 < f) swap(v[p], v[p+1]);
        swap(v[j], v[left]);
        left++;
    } 
  }  swap(v[p],v[left]); 
  return p; */
}

template <typename T>
void quickSort (T *v, int n, int i) {
  if(i <= 0) return;
  int pivot = particionar(v, 0, i, n);
  particionar(v, pivot, (pivot+n)/2, n);
  quickSort(v, n, i/2);
}

int main() {
  int valores[] = {3,8,7,10,9,9,2,1,9,7};
  quickSort(valores, 9, 9/2);

  for(int i = 0; i < 10; i++) {
    cout << valores[i] << ' ';
  }
  return 0;
}
