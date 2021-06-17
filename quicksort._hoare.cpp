template <typename T>
int particionar_h (T *v, int i, int p, int f) {
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
void quicksort_h(T *a, int low, int high) {
    if (low >= high) return;
    int pivot = particionar_h(a, low, pivo(low, high), high);
    quicksort_h(a, low, pivot);
    quicksort_h(a, pivot + 1, high);
}
