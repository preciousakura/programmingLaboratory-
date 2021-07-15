#include <iostream>
#include <ctime>
#include <cstring>
#include "instancias_Reais_Trabalho_2.hpp"

using std::time;
using std::cout;

bool comparar(int* fc, int* kmp, int tam) {
  for(int i = 0; i < tam; i++) {
    if(fc[i] != kmp[i]) return false;
  } return true;
}

double aferir_time(clock_t i,  clock_t f) {
  return (f-i) / (double) CLOCKS_PER_SEC;
}

int count_str(const char* s, unsigned int size) { // contar números de caracteres
  if(s[size] == '\0') return size;
  return count_str(s, ++size);
}

// força bruta

void forca_bruta(const char* P, const char* T, int *O) {
  for(const char* i = T; *i != '\0'; ++i) {
    const char *j = i, *k = P;
    while(*k != '\0' && *j == *k) { ++j; ++k; }
    if(*k == '\0') { *O = i - T; ++O;}
  } *O = -1;
}

// kmp

void prefix(const char* P, int* A, int size) {
  int i = 1, j = 0; 
  A[0] = 0;
  while(i < size) {
    if(P[i] == P[j]) {
      ++j;
      A[i] = j;
      ++i;
    } else {
      if(j != 0) j = A[j-1];
      else { A[i] = 0; ++i; }
    }
  } 
}

bool kmp(const char *P, const char *T, int *O) {
  int size_p = count_str(P, 0); // tamanho do padrão
  int *A = new int[size_p]; 
  if(A != nullptr) { 
    prefix(P, A, size_p); // computa o prefixo  
    const char *i = T, *j = P;
    while (*i != '\0') {
      while (*j != '\0' && *i == *j){ ++i; ++j; }
      if(*j == '\0') {
        *O = (i - T) - (j - P);
        ++O;
      }
      if(j - P == 0) ++i;
      else j = P + A[(j - P) - 1];
    }
    delete [] A; 
    *O = -1; 
    return true;
  } else return false;
}

int main(int argc, char *argv[]) {
  srand((unsigned int) time(nullptr));
  
  if(argc > 1) {
    clock_t t;
    
    double fc_time = 0, kmp_time = 0;
    
    char tipo_instancia = argv[1][0], 
         l; // última letra
         
    int m = 0, // tamanho padrao
        n = 0, // tamanho texto
        I = 0, // número de instâncias
        *O_fc, *O_kmp; // posicação padrao dos arrays

    int x, y;
    
    if(tipo_instancia == 'A') {
      l = argv[2][0];
      m = atoi(argv[3]);
      n = atoi(argv[4]);
      I = atoi(argv[5]);
      
      O_fc = new int[n + 1] {0};
      if(!O_fc) return 1;

      O_kmp = new int[n + 1] {0};
      if(!O_kmp) return 1;
      
      char *T = new char[n]; // texto aleatório
      if(!T) return 1;
      
      char *P = new char[m]; // padrão aleatório
      if(!P) return 1;

      for(int k = 0; k < I; k++) {
        for (int k = 0; k < n; k++)
          T[k] = (int)'a' + (rand() % (l - (int)'a' + 1));

        for (int k = 0; k < m; k++)
          P[k] = (int)'a' + (rand() % (l - (int)'a' + 1));
      
        t = clock();
        forca_bruta(P, T, O_fc);
        fc_time += aferir_time(t, clock());
      
        t = clock();
        kmp(P, T, O_kmp);
        kmp_time += aferir_time(t, clock());

        if(!comparar(O_fc, O_kmp, n+1)) {
          cout << "Saidas diferentes";
          return 1;
        } 
      }

      delete []O_fc;
      delete []O_kmp;
      delete []T;
      delete []P;

    } else if(tipo_instancia == 'R') {
      x = atoi(argv[2]);
      y = atoi(argv[3]);

      if((x < 0 || x > 35129) || (y < 0 || y > 35129)) return 1;

      int size = strlen(Texto_Livros) + 1;

      O_fc = new int[size + 1] {0};
      if(!O_fc) return 1;

      O_kmp = new int[size + 1] {0};
      if(!O_kmp) return 1;

      for (int i = x; i <= y; i++) {
        t = clock();
        forca_bruta(Padroes_Palavras[i], Texto_Livros, O_fc);
        fc_time += aferir_time(t, clock());

        t = clock();
        kmp(Padroes_Palavras[i], Texto_Livros, O_kmp);
        kmp_time += aferir_time(t, clock());

        if(!comparar(O_fc, O_kmp, n+1)) {
          cout << "Saidas diferentes";
          return 1;
        } 
      }
    }
    cout << "\n---- TEMPOS ---- \n";
    cout << "Força bruta: " << fc_time << " segundos.\n";
    cout << "Knuth-Morris-Pratt (KMP): " << kmp_time << " segundos.\n";
  }
  return 0;
}