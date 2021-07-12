#include <iostream>
using std::cout;

int count_str(const char* s, int size) {
  if(s[size] == '\0') return size;
  return count_str(s, ++size);
}

bool alocacao(int size, int* currentArray) {
  int *newArray = new int[size]; 
  if(newArray == nullptr) return false;
  else { for(int i = 0; i < size; i++) newArray[i] = currentArray[i]; }
  currentArray = newArray;
  return true;
}

bool prefix(const char* P, int* O) {
  int size = count_str(P, 0); // tamanho do padrão
  if(alocacao(size, O)) {
    int i = 1, j = 0; 
    O[0] = 0;
    while(i < size) {
      if(P[i] == P[j]) {
        ++j;
        O[i] = j;
        ++i;
      } else {
        if(j != 0) j = O[j-1];
        else { O[i] = 0; ++i; }
      }
    } return true;
  } else return false;
}

bool kmp(const char *P, const char *T, int *O) {
  int size_text = count_str(T, 0); // tamanho do texto  
  int size_p = count_str(P, 0); // tamanho do padrão  
  int i = 0, j = 0;
  while(i < size_text) {
    if(P[j] == T[i]) { ++i; ++j; }
    if(j == size_p) { j = O[j-1]; }  // padrão encontrado
    else {
      if(j < size_p && P[j] != T[i]) {
        if(j != 0) j = O[j-1];
        else ++i;
      }
    }
  }
}

int main() {
  int *A = new int[1]; 
  prefix("isabelisa", A);
  kmp("isabelisa", "isabelisa isabelisaloveamoisabelisa isabel", A);
  for(int i = 0; i < 9; i++) cout << A[i] << ' ';
  return 0;
}