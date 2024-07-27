#include <stdio.h>
#include <string.h>
int main() {
    char code[1000];
    printf("Enter the code: ");
    fgets(code, sizeof(code), stdin);
    int length = strlen(code);
    int i = 0;
    while (i < length) {
        if (code[i] == '/' && code[i + 1] == '/') {
            printf("single line comment: ");
            i += 2;
            }    
        else if (code[i] == '/' && code[i + 1] == '*') {
            printf("multi line comment: ");
            i += 2;
            printf("\n");
        } else {
            i++;
        }
    }
    return 0;
}
