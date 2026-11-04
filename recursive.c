#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *input;
char lookahead;

void E();
void Eprime();
void T();
void Tprime();
void F();

void nextToken() {
    while (isspace((unsigned char)*input))
        input++;
    lookahead = *input++;
}

void match(char ch) {
    if (lookahead == ch)
        nextToken();
    else {
        printf("Syntax Error\n");
        exit(1);
    }
}

void F() {
    if (lookahead == '(') {
        match('(');
        E();
        match(')');
    }
    else if (isalpha((unsigned char)lookahead)) {
        while (isalnum((unsigned char)lookahead))
            nextToken();
    }
    else {
        printf("Syntax Error\n");
        exit(1);
    }
}

void Tprime() {
    if (lookahead == '*') {
        match('*');
        F();
        Tprime();
    }
}

void T() {
    F();
    Tprime();
}

void Eprime() {
    if (lookahead == '+') {
        match('+');
        T();
        Eprime();
    }
}

void E() {
    T();
    Eprime();
}

int main() {
    char expr[100];

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    input = expr;
    nextToken();

    E();

    if (lookahead == '\0')
        printf("Parsing Successful\n");
    else
        printf("Syntax Error\n");

    return 0;
}
// a+b*c
