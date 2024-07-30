#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_SYMBOLS 50

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

typedef struct {
    char nonTerm;
    char follow[MAX_SYMBOLS];
} FollowSet;

int numProductions;
Production productions[MAX];
FollowSet followSets[MAX_SYMBOLS];
int numNonTerminals;
char nonTerminals[MAX_SYMBOLS];
char startSymbol;

int isNonTerminal(char symbol) {
    return isupper(symbol);
}

void addFollow(char nonTerm, char symbol) {
    for (int i = 0; i < numNonTerminals; i++) {
        if (followSets[i].nonTerm == nonTerm) {
            if (!strchr(followSets[i].follow, symbol)) {
                int len = strlen(followSets[i].follow);
                followSets[i].follow[len] = symbol;
                followSets[i].follow[len + 1] = '\0';
            }
            break;
        }
    }
}

void computeFollowSets() {
    // Initialize follow sets with the start symbol
    addFollow(startSymbol, '$');

    int changes = 1;
    while (changes) {
        changes = 0;

        for (int i = 0; i < numProductions; i++) {
            char *rhs = productions[i].rhs;
            char lhs = productions[i].lhs;

            for (int j = 0; rhs[j] != '\0'; j++) {
                if (isNonTerminal(rhs[j])) {
                    int k;
                    for (k = j + 1; rhs[k] != '\0'; k++) {
                        if (isNonTerminal(rhs[k])) {
                            // Copy first of rhs[k] to follow of rhs[j]
                            for (int m = 0; m < numNonTerminals; m++) {
                                if (followSets[m].nonTerm == rhs[k]) {
                                    for (int n = 0; followSets[m].follow[n] != '\0'; n++) {
                                        if (followSets[m].follow[n] != 'e') {
                                            int len = strlen(followSets[m].follow);
                                            addFollow(rhs[j], followSets[m].follow[n]);
                                            changes = 1;
                                        }
                                    }
                                    break;
                                }
                            }
                        } else {
                            addFollow(rhs[j], rhs[k]);
                            break;
                        }
                    }

                    if (rhs[k] == '\0' || (isNonTerminal(rhs[k]) && strchr(followSets[j].follow, 'e'))) {
                        // Copy follow of lhs to follow of rhs[j]
                        for (int m = 0; m < numNonTerminals; m++) {
                            if (followSets[m].nonTerm == lhs) {
                                for (int n = 0; followSets[m].follow[n] != '\0'; n++) {
                                    addFollow(rhs[j], followSets[m].follow[n]);
                                    changes = 1;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions (e.g., E->E+T):\n");
    for (int i = 0; i < numProductions; i++) {
        char buffer[MAX];
        scanf("%s", buffer);

        productions[i].lhs = buffer[0];
        strcpy(productions[i].rhs, buffer + 3);

        if (!strchr(nonTerminals, productions[i].lhs)) {
            nonTerminals[numNonTerminals++] = productions[i].lhs;
        }
    }

    startSymbol = productions[0].lhs;

    for (int i = 0; i < numNonTerminals; i++) {
        followSets[i].nonTerm = nonTerminals[i];
        followSets[i].follow[0] = '\0';
    }

    computeFollowSets();

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FOLLOW(%c) = { %s }\n", followSets[i].nonTerm, followSets[i].follow);
    }

    return 0;
}

