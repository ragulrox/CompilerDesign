#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

Quadruple quads[100];
int quadCount = 0;

void generate(char *op, char *arg1, char *arg2, char *result) {
    strcpy(quads[quadCount].op, op);
    strcpy(quads[quadCount].arg1, arg1);
    strcpy(quads[quadCount].arg2, arg2);
    strcpy(quads[quadCount].result, result);
    quadCount++;
}

void printIntermediateCode() {
    printf("\nIntermediate Code:\n");
    for(int i = 0; i < quadCount; i++) {
        printf("%s = %s %s %s\n", quads[i].result, quads[i].arg1, quads[i].op, quads[i].arg2);
    }
}

int main() {
    char expr[100];
    printf("Enter a simple expression (e.g., a = b + c): ");
    gets(expr);

    char lhs[10], rhs[10], op[3], arg1[10], arg2[10];
    sscanf(expr, "%s = %s %s %s", lhs, arg1, op, arg2);

    generate(op, arg1, arg2, lhs);
    printIntermediateCode();

    return 0;
}
