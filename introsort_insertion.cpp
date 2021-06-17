template <typename T>
void intro_rec_insertion(T *v, int i, int f, int p, int tam) {
  if(f <= 1) return;
  if(p <= 1) heapsort(v+i, f-i+1);
  else if(tam < 32) insertionSort(v, tam, 0);
  else {
    if (i >= f) return;
    int pivot = particionar_h(v, i, (i+f)/2, f);
    intro_rec_insertion(v, i, pivot, p-1, tam);
    intro_rec_insertion(v, pivot + 1, f, p-1, tam);
  }
}

template <typename T>
void introSort_insertion(T *v, int n){
  int p = n;
  int i = 0;
  while(p != 1) {
    p >>= 1;
    i++;
  }
  intro_rec_insertion(v, 0, n-1, p, n);
}
