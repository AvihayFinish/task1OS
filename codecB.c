#include <string.h>
#include <stdio.h>

void encode (char* st, size_t size) {
    for (int i = 0; i< size; i++) {
        st[i] = (st[i] + 3) % 256; 
    }
    printf("%s" , st);
}

void decode (char* st, size_t size) {
    for (int i = 0; i< size; i++) {
        st[i] = (st[i] - 3) % 256; 
    }
    printf("%s" , st);
}