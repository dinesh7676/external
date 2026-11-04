#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

char productions[MAX][MAX], first[26][MAX];
int n = 0;

int isTerminal(char s) {
    return !isupper(s) && s != '#';
}

void addToFirst(char nt, char s) {
    int i = nt - 'A';
    if (!strchr(first[i], s)) {
        int l = strlen(first[i]);
        first[i][l] = s;
        first[i][l + 1] = '\0';
    }
}

void findFirst(char nt) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nt) {
            char next = productions[i][2];

            if (isTerminal(next))
                addToFirst(nt, next);
            else if (next != nt) {
                if (!first[next - 'A'][0])
                    findFirst(next);

                for (int k = 0; first[next - 'A'][k]; k++)
                    addToFirst(nt, first[next - 'A'][k]);
            }

            if (next == '#')
                addToFirst(nt, '#');
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", productions[i]);

    for (int i = 0; i < n; i++)
        findFirst(productions[i][0]);

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        char nt = productions[i][0];

        if (first[nt - 'A'][0]) {
            printf("FIRST(%c) = { ", nt);
            for (int j = 0; first[nt - 'A'][j]; j++)
                printf("%c ", first[nt - 'A'][j]);
            printf("}\n");
            first[nt - 'A'][0] = '\0';
        }
    }
    return 0;
}
// E=E+T
// E=T
// T=T*F
// T=F
// F=(E)
// F=i
