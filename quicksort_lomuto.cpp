#include <iostream>
#include <algorithm>
using std::cout;
using std::swap;

template <typename T>
int particionar (T *v, int i, int p, int f) {

  int left = i + 1;
  swap(v[p], v[i]);
  p = i;
  for(int j = left; j <= f; j++) {
    if(v[j] < v[p]) {
        swap(v[j], v[left]);
        left++;
    } 
  } swap(v[p], v[left-1]); 
  return left-1; 
}

template <typename T>
void quickSort(T *a, int low, int high)
{
	if (low < high) {
		int index_pivot = particionar(a, low, (low+high)/2, high);
		quickSort(a, low, index_pivot - 1);
		quickSort(a, index_pivot + 1, high);	
	}
}

int main() {
  int v[] = {0,1,0,10,1,0,1,0,1,0,1,0,10,10,500};
  quickSort(v, 0, sizeof(v)/sizeof(v[0]) - 1);

  for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    cout << v[i] << ' ';
  }
  return 0;
}
