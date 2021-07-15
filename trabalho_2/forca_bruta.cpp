void forca_bruta(const char* P, const char* T, int *O) {
  for(const char* i = T; *i != '\0'; ++i) {
    const char *j = i, *k = P;
    while(*k != '\0' && *j == *k) { ++j; ++k; }
    if(*k == '\0') { *O = i - T; ++O;}
  } *O = -1;
}