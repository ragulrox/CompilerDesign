#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char productions[MAX][MAX], first[MAX][MAX];
int n;

void findFirst(char, int, int);
void addToFirst(char, int);

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    for (int i = 0; i < n; i++) findFirst(productions[i][0], i, i);

    printf("First Sets:\n");
    for (int i = 0; i < n; i++) {
        printf("First(%c) = { ", productions[i][0]);
        for (int j = 0; first[i][j] != '\0'; j++) printf("%c ", first[i][j]);
        printf("}\n");
    }
    return 0;
}

void findFirst(char c, int prodIndex, int firstIndex) {
    if (!isupper(c)) { addToFirst(c, firstIndex); return; }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            for (int j = 2; productions[i][j] != '\0'; j++) {
                if (productions[i][j] == '|') continue;
                findFirst(productions[i][j], i, firstIndex);
                if (!isupper(productions[i][j])) break;
            }
        }
    }
}

void addToFirst(char c, int firstIndex) {
    for (int i = 0; first[firstIndex][i] != '\0'; i++) 
        if (first[firstIndex][i] == c) return;

    int len = strlen(first[firstIndex]);
    first[firstIndex][len] = c;
    first[firstIndex][len + 1] = '\0';
}

