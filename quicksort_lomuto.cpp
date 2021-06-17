template <typename T>
int particionar_l (T *v, int i, int p, int f) {
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
void quicksort_l(T *a, int low, int high)
{
	if (low < high) {
		int index_pivot = particionar_l(a, low, pivo(low, high), high);
		quicksort_l(a, low, index_pivot - 1);
		quicksort_l(a, index_pivot + 1, high);	
	}
}
