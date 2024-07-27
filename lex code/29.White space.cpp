#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char ch;
    int whitespace_count = 0;
    int newline_count = 0;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t') {
            whitespace_count++;
        }
        else if (ch == '\n') {
            newline_count++;
        }
    }
    fclose(fp);
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}

