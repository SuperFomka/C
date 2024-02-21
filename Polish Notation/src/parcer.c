#include <stdio.h>
#include <stdlib.h>

#include "maths.h"
#include "stack.h"

#define sin 'S'
#define cos 'C'
#define tan 'T'
#define ctg 'G'
#define sqrt 'Q'
#define ln 'L'

int Prior(char);
void processFunctions(char A, char B, char C, char D, char E, struct Stack **outputs, char *Out, int *l);

double parcer(char form[100], double x) {
    struct Stack *t, *outputs = NULL;
    char a, Out[100];
    int k = 0, l = 0;
    while (form[k] != '\0') {
        char A, B, C, D, E;
        A = form[k];
        B = form[k + 1];
        C = form[k + 2];
        D = form[k + 3];
        E = form[k + 4];
        if (form[k] == ')') {
            while (outputs && (outputs->c) != '(') {
                outputs = OutString(outputs, &a);
                if (outputs == NULL) {
                    a = '\0';
                }
                Out[l++] = a;
                Out[l++] = ' ';
            }
            if (outputs) {
                t = outputs;
                outputs = outputs->Next;
                free(t);
            }
        }
        processFunctions(A, B, C, D, E, &outputs, Out, &l);
        if ((form[k] == '-' && (k == 0 || form[k - 1] == '('))) {
            outputs = InString(outputs, 'n');
            Out[l++] = ' ';
        } else {
            if (form[k] == '(') outputs = InString(outputs, form[k]);
            if (A == '+' || A == '-' || A == '*' || A == '/' || A == 'S' || A == 'C' || A == 'T' ||
                A == 'G' || A == 'L' || A == 'Q') {
                while (outputs != NULL && Prior(outputs->c) >= Prior(form[k])) {
                    outputs = OutString(outputs, &a);
                    Out[l++] = a;
                    Out[l++] = ' ';
                }
                outputs = InString(outputs, form[k]);
            }
        }
        k++;
    }
    while (outputs != NULL) {
        outputs = OutString(outputs, &a);
        Out[l++] = a;
    }
    Out[l] = '\0';
    return maths(Out, x);
}

int Prior(char a) {
    switch (a) {
        case 'Q':
            return 5;
        case 'S':
        case 'C':
        case 'T':
        case 'G':
        case 'L':
            return 4;
        case '*':
        case '/':
            return 3;
        case '-':
        case '+':
            return 2;
        case '(':
            return 1;
    }
    return 0;
}
void processFunctions(char A, char B, char C, char D, char E, struct Stack **outputs, char *Out, int *l) {
    if (A == 's' && B == 'i' && C == 'n' && D == '(') {
        *outputs = InString(*outputs, sin);
        Out[(*l)++] = ' ';
    } else if (A == 'c' && B == 'o' && C == 's' && D == '(') {
        *outputs = InString(*outputs, cos);
        Out[(*l)++] = ' ';
    } else if (A == 't' && B == 'a' && C == 'n' && D == '(') {
        *outputs = InString(*outputs, tan);
        Out[(*l)++] = ' ';
    } else if (A == 'c' && B == 't' && C == 'g' && D == '(') {
        *outputs = InString(*outputs, ctg);
        Out[(*l)++] = ' ';
    } else if (A == 's' && B == 'q' && C == 'r' && D == 't' && E == '(') {
        *outputs = InString(*outputs, sqrt);
        Out[(*l)++] = ' ';
    } else if (A == 'l' && B == 'n' && C == '(') {
        *outputs = InString(*outputs, ln);
        Out[(*l)++] = ' ';
    } else if (A == 'x') {
        Out[(*l)++] = A;
        Out[(*l)++] = ' ';
    } else if ((A >= '0' && A <= '9') && (B >= '0' && B <= '9')) {
        Out[(*l)++] = A;
    } else if (A >= '0' && A <= '9') {
        Out[(*l)++] = A;
        Out[(*l)++] = ' ';
    }
}
