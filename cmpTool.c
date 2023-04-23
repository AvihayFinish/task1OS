#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isEqual (FILE* fl1 , FILE* fl2, int ignoreCase) {
    int byte1, byte2;
    int checkEqual = 0;
    if (ignoreCase == 0) {
        while ((byte1 = fgetc(fl1)) != EOF && (byte2 = fgetc(fl2)) != EOF) {
            if (byte1 != byte2) {
                checkEqual = 1;
                break;
            }
        }
    }
    else if (ignoreCase == 1) {
        while ((byte1 = fgetc(fl1)) != EOF && (byte2 = fgetc(fl2)) != EOF) {
            if (tolower(byte1) != tolower(byte2)) {
                checkEqual = 1;
                break;
            }
        }
    }
    return checkEqual;
}

void print (int equal) {
    if (equal == 0) {
        printf("%s", "equal");
    }
    else if (equal == 1) {
        printf("%s", "distinct");
    }
}

int main (int argc, char* argv[]) {
    if (argc > 5 || strcmp(argv[0], "./cmp") != 0) {
        char * st = "the format command is not legal, you should run the tool with ./cmp, the names of the files, and the optional flags: \
                    -v to write if the files equal or not, and -i to ignore case sensitive.";
        printf("%s", st);
        exit(0);
    }
    int checkV = 0;
    int checkI = 0;
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            checkV = 1;
        }
        if (strcmp(argv[i], "-i") == 0) {
            checkI = 1;
        }
    }
    if (argc == 4 && checkI == 0 && checkV == 0) {
        printf("%s", "the flag is not legal, the legal flags is: -v to write if the files equal or not, -i to ignore case sensitive.");
        exit(0);
    }
    if (argc == 5 && ((checkI == 0 || checkV == 0))) {
        printf("%s", "one of the flags is not legal, the legal flags is: -v to write if the files equal or not, -i to ignore case sensitive.");
        exit(0);
    }
    char* name1 = argv[1];
    char* name2 = argv[2];
    FILE* fl1 = fopen(name1, "r");
    FILE* fl2 = fopen(name2, "r");
    if (fl1 == NULL || fl2 == NULL) {
        printf("%s", "one of the files dont exsit");
        exit(0);
    }
    if (argc == 5) {
        int isEqualReturn = isEqual(fl1, fl2, checkI);
        print(isEqualReturn);
    }
    if (argc == 4) {
        if (checkI == 1) {
            int isEqualReturn = isEqual(fl1, fl2, checkI);
            printf("%d", isEqualReturn);
        }
        else if (checkV == 1) {
            int isEqualReturn = isEqual(fl1, fl2, 0);
            print(isEqualReturn);
        }
    }
    if (argc == 3) {
        int isEqualReturn = isEqual(fl1, fl2, 0);
            printf("%d", isEqualReturn);
    }
    fclose(fl1);
    fclose(fl2);

    return 0;
}