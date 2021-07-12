#include <iostream>
using std::cout;

void forca_bruta(const char* T, const char* P, int *o) {
  for(const char* i = T; *i != '\0'; ++i) {
    const char *j = i, *k = P;
    while(*k != '\0' && *j == *k) { ++j; ++k; }
    if(*k == '\0') { *o = i - T; ++o;}
  }
  *o = -1;
}

int main(){
  int o[100];
  forca_bruta("isabel isabel isabel", "isabel", o);

  int i = 0;
  while(o[i] != -1) {
    cout << o[i] << ' ';
    i++;
  }
  return 0;
}