int count_str(const char* s, unsigned int size) { // contar números de caracteres
  if(s[size] == '\0') return size;
  return count_str(s, ++size);
}

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

    while(*i != '\0') {
      if(*j == *i) { ++i; ++j; }

      if(*j == '\0') { // padrão encontrado
        *O = (i - T) - (j - P); ++O;
        j = j = P + A[(j - P) - 1]; 
      }

      else {
        if(*j != *i) {
          if(j - P != 0) j = j = P + A[(j - P) - 1];
          else ++i;
        }
      }
    }
    delete []A; *O = -1; return true;
  } else return false;
}