#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cstdlib>
using std::time;
using std::srand;
using std::cout; 
using std::swap;
using std::atoi;


double aferir_time(clock_t i,  clock_t f){
  return (f-i) / (double) CLOCKS_PER_SEC;
}

template <typename T>
T gerar_num(int de, int ate) {
  return de + rand() % ((ate+1) - de);
}

int pivo (int inicio, int fim) { 
  return (inicio+fim)/2;
}

template <typename T>
T* copy(T* v, int tam) {
  T* aux = new T[tam]; 
  for(int i = 0; i < tam; i++) aux[i] = v[i];
  return aux;
}

/* ----- funções geradoras de instâncias ----- */

// pior caso para quicksort

template <typename T>
bool gerar_pior_caso_rec(T *v, int i, int f) {
  if(i>f) return false;
  int pivot = pivo(i, f);  
  swap(v[i], v[pivot]);
  gerar_pior_caso_rec(v, pivot+1, f);
  return true;
}

// sequência aleatória

template <typename T>
T* gerar_seq_rand(long tam, int de, int ate) {
  T *v = new T[tam]; 
  for(int i = 0; i < tam; i++){
    v[i] = gerar_num<T>(de, ate);
  }
  return v;
}

// sequência aleatória crescente

template <typename T>
T* gerar_seq_cres(long tam, int de, int ate) {
  T *v = new T[tam]; 
  for(int i = 0; i < tam; i++){
    v[i] = gerar_num<T>(de, ate);
    int p = i;
    while(v[p] < v[p-1] && p-1 >= 0 && p >= 0) { 
      swap(v[p], v[p-1]); 
      p--;
    }
  }
  return v;
}

// sequência aleatória decrescente

template <typename T>
T* gerar_seq_dec(long tam, int de, int ate) {
  T *v = new T[tam]; 
  for(int i = 0; i < tam; i++){
    v[i] = gerar_num<T>(de, ate);
    int p = i;
    while(v[p] > v[p-1] && p-1 >= 0 && p >= 0) { 
      swap(v[p], v[p-1]); 
      p--;
    }
  }
  return v;
}


/* ----- fim das funções geradoras de instâncias ----- */

/* ----- funções de ordenação ----- */

// insertion sort

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

// heapsort

template <typename T>
int descer(T *v, int n, int i) {
  int left_child, right_child, largest;
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
  } return i;
 }

template <typename T>
void heapsort (T *v, int n) {
  int levels = log2(n); // number of levels in the tree, n = number of nodes total
  int n_leaf_nodes = pow(2, (levels-1) + 1) - 1; // number of non- leaf nodes.
  for(int i = n_leaf_nodes - 1; i >= 0; i--) {
    	descer(v, n, i);
  }
  for(int i = n-1; i >= 0; i--) {
    if(v[0] > v[i]) {
      swap(v[0], v[i]);
      descer(v, i, 0);
    }
  }	
}

// quicksort lomuto

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

// quicksort hoare / pivô fixo

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

// quicksort hoare / pivô aleatorio

template <typename T>
void quicksort_l_rand(T *a, int low, int high) {
    if (low >= high) return;
    int pivot = particionar_l(a, low, gerar_num<int>(low, high), high);
    quicksort_l_rand(a, low, pivot);
    quicksort_l_rand(a, pivot + 1, high);
}

// introsort sem insertion sort

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

// introsort com insertion sort

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
  p = (i<<1)+1;
  intro_rec_insertion(v, 0, n-1, p, n);
}

/* ----- fim das funções de ordenação ----- */

bool ordenado(int arr[], int n) {
	for(int i = 0; i < n-1; i++) {
		if(arr[i] > arr[i+1])
			return false;
	}
	return true;
}

void mostrar_ordenado(int arr[], int n) {
	if(not ordenado(arr, n)) {
		std::cout << "nao esta ordenado" << std::endl;
	}
}

int main(int argc, char *argv[]) {
  srand((unsigned int) time(nullptr));


  double t_hp = 0, // heapsort
         t_qs_l = 0, // quicksort lomuto pivo fixo
         t_qs_h = 0, // quicksort hoare pivo fixo
         t_qs_pa = 0, // quicksort hoare pivo aleatorio
         t_is_si = 0, // introsort sem insertionsort
         t_is_ci = 0; // introsort com insertionsort

  int *instancia, *copy_instancia;
  int tamanho, num_inst;
  clock_t i; // inicial time

  if(argc > 3) {
    tamanho = atoi(argv[2]);
    num_inst = atoi(argv[3]);
    while(num_inst > 0) {
      if(argv[1][0] == 'A' || argv[1][0] == 'a') {
        instancia = gerar_seq_rand<int>(tamanho, 0, tamanho);
      } else if(argv[1][0] == 'C' || argv[1][0] == 'c') {
        instancia = gerar_seq_cres<int>(tamanho, 0, tamanho);
      } else if(argv[1][0] == 'D' || argv[1][0] == 'd') {
        instancia = gerar_seq_dec<int>(tamanho, 0, tamanho);
      } else if(argv[1][0] == 'P' || argv[1][0] == 'p') {
        instancia = gerar_seq_cres<int>(tamanho, 0, tamanho);
        gerar_pior_caso_rec(instancia, 0, tamanho-1);
      } 

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      heapsort(copy_instancia, tamanho);
      t_hp += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      quicksort_l(copy_instancia, 0, tamanho-1);
      t_qs_l += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      quicksort_h(copy_instancia, 0, tamanho-1);
      t_qs_h += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      quicksort_l_rand(copy_instancia, 0, tamanho-1);
      t_qs_pa += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      introSort(copy_instancia, tamanho);
      t_is_si += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      copy_instancia = copy(instancia, tamanho);
      i = clock();
      introSort_insertion(copy_instancia, tamanho);
      t_is_ci += aferir_time(i, clock());
      mostrar_ordenado(copy_instancia, tamanho);

      num_inst--;
    }
    cout << "\n---- TEMPOS ---- \n";
    cout << "HeapSort: " << t_hp << " segundos.\n";
    cout << "QuickSort (Lomuto): " << t_qs_l << " segundos.\n";
    cout << "QuickSort (Hoare): " << t_qs_h << " segundos.\n";
    cout << "Quicksort pivô aleatório (Hoare): " << t_qs_pa << " segundos.\n";
    cout << "IntroSort sem InsertionSort: " << t_is_si << " segundos.\n";
    cout << "IntroSort com InsertionSort: " << t_is_ci << " segundos.\n";

    delete []instancia;
    delete []copy_instancia;
  }
  return 0;
}
