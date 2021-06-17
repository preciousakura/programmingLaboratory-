template <typename T>
void intro_rec(T *v, int i, int f, int p) {
  if(f <= 1) return;
  if(p <= 1) heapsort(v+i, f-i+1);
  else {
    if (i >= f) return;
    int pivot = particionar_h(v, i, (i+f)/2, f);
    intro_rec(v, i, pivot, p-1);
    intro_rec(v, pivot + 1, f, p-1);
  }
}

template <typename T>
void introSort(T *v, int n){
  int p = n;
  int i = 0;
  while(p != 1) {
    p >>= 1;
    i++;
  }
  p = (i<<1)+1;
  intro_rec(v, 0, n-1, p);
}
