#include <iostream>
using std::cin; using std::cout;

int contarCaractere(const char *t, int i) {
  if(t[i] == '\0') return i;
  contarCaractere(t, i+1);
}

void forca_bruta(const char* t, const char *p, int* o) {
  int tamanho_texto = contarCaractere(t, 0);
  int parte_texto = contarCaractere(p, 0);
  int i = 0, // tamanho do texto
      k = 0, // comparar
      j = 0; // tamanho da parte do texto
  while(i < tamanho_texto) {
    if(t[i] == p[j] && t[i] != ' ') {
      k = i;
      while(t[k] == p[j] && j < parte_texto && k < tamanho_texto) { k++; j++; }
      if (j == parte_texto) {
        int p = 0;
        while(o[p] != -1) p++;
        o[p] = i;
        o[p+1] = -1;
      } j = 0;
    }
    i++;
  }
}

int main(){
  int o[100];
  o[0] = -1;
  forca_bruta("isabel isA ISABEL", "isabel", o);

  int i = 0;
  while(o[i] != -1) {
    cout << o[i] << ' ';
    i++;
  }
  return 0;
}