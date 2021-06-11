#include <iostream>
#include <algorithm>
using std::cout;
using std::swap;

template <typename T>
int particionar (T *v, int i, int p, int f) {
  int left = i;
  for(int j = i; j <= f; j++) {
    if(v[j] <= v[p] && j != p) {
        if(p == left && p+1 < f) swap(v[p], v[p+1]);
        swap(v[j], v[left]);
        left++;
    } 
  }  swap(v[p],v[left]); 
  return p; 
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
  int v[] = {2,1,2,1,2,100,2,1,2,1,2,1,2,1,2};
  quickSort(v, (sizeof(v)/sizeof(v[0]))-1);

  for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}

