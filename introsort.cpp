#include <iostream>
#include <math.h>
#include <algorithm>
using std::cout;
using std::swap;

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
    swap(v[i], v[largest]);
    flag = (i != largest);
		i = largest;
  }
  return i;
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
void intro_rec(T *v, int i, int f, int p) {
  if(f <= 1) return;
  if(p < 1) heapsort(v, f);
  else {
    if (i >= f) return;
    int pivot = particionar(v, i, (i+f)/2, f);
    intro_rec(v, i, pivot, p-1);
    intro_rec(v, pivot + 1, f, p-1);
  }
}

template <typename T>
void introSort(T *v, int n){
  int p = 2 * (n>>2);
  
  intro_rec(v, 0, n-1, p);
}

int main() {
  int v[] = {0,1,2,3,5,4,6,7,8,9,10,11,12,14,13,15,16,17,19,20,21,25,26,27,28,19,20,255,2669,0,40,41,42,43,44,45,46,47,48,49,50};

  introSort(v, sizeof(v)/sizeof(v[0]));

  for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
    cout << v[i] << ' ';
  }
}