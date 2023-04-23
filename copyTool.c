#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int copyFile (FILE* fl1, FILE* fl2, int exist, int checkf) {
    if (exist == 0) {
        char buffer[1024];
        size_t bytesToCopy;
        while ((bytesToCopy = fread(buffer, sizeof(char), sizeof(buffer), fl1)) > 0) {
            fwrite(buffer, sizeof(char), bytesToCopy, fl2);
        }
        return 0;
    }
    else if (exist && checkf) {
        char buffer[1024];
        size_t bytesToCopy;
        while ((bytesToCopy = fread(buffer, sizeof(char), sizeof(buffer), fl1)) > 0) {
            fwrite(buffer, sizeof(char), bytesToCopy, fl2);
        }
        return 0;
    }
    else if (exist && !checkf) {
        return 2;
    }
}

void print (int sucOrNot, int exist) {
    if (exist && sucOrNot == 2) {
        printf("%s", "the file is exist, if you want to overwite him use the -f flag.");
    }
    else if (!sucOrNot) {
        printf("%s", "success.");
    }
    else {
        printf("%s", "failure.");
    }
}


int main (int argc, char* argv[]) {
    if (argc < 3) {
        char * st = "the format command is not legal, you should run the tool with ./copy, the names of two files, and the optional flags: \
                    -v to write if the copy files success or not, and -f to force overwite exist files.";
        printf("%s", st);
        exit(0);
    }
    if (argc > 5 || strcmp(argv[0], "./copy") != 0) {
        char * st = "the format command is not legal, you should run the tool with ./copy, the names of the files, and the optional flags: \
                    -v to write if the copy files success or not, and -f to force overwite exist files.";
        printf("%s", st);
        exit(0);
    }
    int checkV = 0;
    int checkF = 0;
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            checkV = 1;
        }
        if (strcmp(argv[i], "-f") == 0) {
            checkF = 1;
        }
    }
    if (argc == 4 && checkF == 0 && checkV == 0) {
        printf("%s", "the flag is not legal, the legal flags is: -v to write if the files equal or not, -i to ignore case sensitive.");
        exit(0);
    }
    if (argc == 5 && ((checkF == 0 || checkV == 0))) {
        printf("%s", "one of the flags is not legal, the legal flags is: -v to write if the files equal or not, -i to ignore case sensitive.");
        exit(0);
    }
    char* name1 = argv[1];
    char* name2 = argv[2];
    int exist = 1;
    if (access(name2, F_OK) == -1) {
        exist = 0;
    }
    FILE* fl1 = fopen(name1, "r");
    FILE* fl2 = fopen(name2, "w+");
    if (fl1 == NULL || fl2 == NULL) {
        printf("%s", "there is a some problem with open the files.");
        exit(0);
    }
    int returnValue = copyFile(fl1, fl2, exist, checkF);
    if (checkV) {
        print(returnValue, exist);
    }
    else {
        printf("%d", returnValue);
    }

    fclose(fl1);
    fclose(fl2);
    
    return 0;

}