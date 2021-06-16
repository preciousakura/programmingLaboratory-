template <typename T>
void insertionSort(T *v, int n, int i) {
  if(i > n) return;
  int p = i;
  while(v[p] < v[p-1] && p-1 >= 0 && p >= 0) { 
    swap(v[p], v[p-1]); 
    p--;
  }
  insertionSort(v, n, i+1);
}