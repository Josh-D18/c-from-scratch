#ifndef converter
#define converter
#include <stdio.h>

struct WordBlob {
    char blob[100];
};

const int handleFileFunc(char* filename);

const int findLen(char* filename);

#endif
