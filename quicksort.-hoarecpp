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
      while(v[right] >= v[p] && right > left) { // setinha direita
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
  int v[] = {1,5,4,0,2,3,10,50,55,0,0,850,0};
  quickSort(v, (sizeof(v)/sizeof(v[0]))-1);

  for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
