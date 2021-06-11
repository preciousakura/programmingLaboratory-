#include <iostream>
#include <algorithm>
using std::cout;
using std::swap;

template <typename T>
int particionar (T *v, int i, int p, int f) {
  int left = i+1;
  int right = f;
  swap(v[p], v[i]);
  p = i;
  while (left <= right) {
    if(v[left] >= v[p]) { 
      while(v[right] >= v[p] && right > left ) right--;
      swap(v[left], v[right]); 
      right--;
    } left++;
  } 
  left = i + 1;
  while(v[left] < v[p] && left <= f) {
    left++;
  } swap(v[left-1], v[p]);
  return left - 1;
}

template <typename T>
void quicksort(T *a, int low, int high)
{
    if (low >= high) return;
    int pivot = particionar(a, low, (low+high)/2, high);
    quicksort(a, low, pivot);
    quicksort(a, pivot + 1, high);
}

int main() {
  int v[] = {100, 200, 300, 400, 0, 500, 1500, 600};
  quicksort(v, 0, 7);

  for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
