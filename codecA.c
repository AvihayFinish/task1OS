#include <string.h>
#include <stdio.h>
#include <ctype.h>

void encode (char* st, size_t size) {
    for (int i = 0; i < size; i++) {
        if (st[i] >= 'A' && st[i] <= 'Z') {
            st[i] = tolower(st[i]);
        }
        else if (st[i] >= 'a' && st[i] <= 'z') {
            st[i] = toupper(st[i]);
        }
    }
    printf("%s", st);
}

void decode (char* st, size_t size) {
    encode(st, size);
}