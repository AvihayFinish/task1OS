#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

void (*ptFunc)(char*, size_t);

int initLibrary (char* st) {
    char* stp = (char*)malloc(strlen(st) + 3);
    if (stp == NULL) {
        return 0;
    }
    strcat(stp, "./");
    strcat(stp, st);
    void* hdl = dlopen(stp, RTLD_LAZY);
    free(stp);
    if (hdl == NULL) {
        return 0;
    }
    ptFunc = (void(*)(char*))dlsym(hdl, "decode");
    if (ptFunc == NULL) {
        return 0;
    }
    return 1;
}

int main (int argc, char* argv[]) {
    if (argc > 3) {
        printf("%s", "there is a problem with the run command, you should use this coomand - ./encode codecA/codecB and your string");
        exit(0);
    }
    else if (initLibrary(argv[1])){
        ptFunc(argv[2], strlen(argv[2]));
    }
    else {
        printf("%s", "there is a problem with load the library");
    }

}