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
    char alpha[MAX][MAX_LEN], beta[MAX][MAX_LEN];
    int alpha_count = 0, beta_count = 0;
    for (int i = 0; i < prod_count; i++) {
        if (productions[i][0] == non_terminal) {
            strcpy(alpha[alpha_count++], productions[i] + 1);
        } else {
            strcpy(beta[beta_count++], productions[i]);
        }
    }
    if (alpha_count > 0) {
        printf("After removing left recursion:\n");
        printf("%c -> ", non_terminal);
        for (int i = 0; i < beta_count; i++) {
            printf("%s%c'", beta[i], non_terminal);
            if (i != beta_count - 1) printf(" | ");
        }
        printf("\n");

        printf("%c' -> ", non_terminal);
        for (int i = 0; i < alpha_count; i++) {
            printf("%s%c'", alpha[i], non_terminal);
            if (i != alpha_count - 1) printf(" | ");
        }
        printf(" | e\n");
    } else {
        printf("No left recursion detected for %c\n", non_terminal);
    }
    return 0;
}
