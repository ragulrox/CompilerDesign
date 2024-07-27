#include <stdio.h>
#include <string.h>
#define MAX 10
#define MAX_LEN 100
int main() {
    char non_terminal;
    int prod_count;
    char productions[MAX][MAX_LEN];
    printf("Enter the non-terminal: ");
    scanf(" %c", &non_terminal);
    printf("Enter the number of productions: ");
    scanf("%d", &prod_count);
    printf("Enter the productions (use %c as the non-terminal):\n", non_terminal);
    for (int i = 0; i < prod_count; i++) {
        printf("%c -> ", non_terminal);
        scanf("%s", productions[i]);
    }
    char common_prefix[MAX_LEN];
    int prefix_len = 0, i, j;
    for (i = 0; i < strlen(productions[0]); i++) {
        char current_char = productions[0][i];
        for (j = 1; j < prod_count; j++) {
            if (productions[j][i] != current_char) break;
        }
        if (j < prod_count) break; 
        common_prefix[prefix_len++] = current_char;
    }
    common_prefix[prefix_len] = '\0';
    if (prefix_len == 0) {
        printf("No common prefix found. No left factoring needed.\n");
        return 0;
    }
    printf("After left factoring:\n");
    printf("%c -> %s%c'\n", non_terminal, common_prefix, non_terminal);
    printf("%c' -> ", non_terminal);
    for (i = 0; i < prod_count; i++) {
        if (strlen(productions[i]) == prefix_len) {
            printf("e");
        } else {
            printf("%s", productions[i] + prefix_len);
        }
        if (i != prod_count - 1) printf(" | ");
    }
    printf("\n");
    return 0;
}

