#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void add(double* strings, int* pos_str);
void subtract(double* strings, int* pos_str);
void subtracts(double* strings, const int* pos_str);
void multiply(double* strings, int* pos_str);
void divide(double* strings, int* pos_str);
void calculate_sin(double* strings, const int* pos_str);
void calculate_cos(double* strings, const int* pos_str);
void calculate_tan(double* strings, const int* pos_str);
void calculate_cot(double* strings, const int* pos_str);
void calculate_sqrt(double* strings, const int* pos_str);
void calculate_log(double* strings, const int* pos_str);
void X(double* strings, int* pos_str, double x);

double maths(const char a[100], double x) {
    double strings[300];
    int exit_flag = 0, pos_str = 0, id_a = 0;
    while (exit_flag == 0) {
        char c = a[id_a];
        if (c != '\0') {
            if (c == ' ') {
            } else if (c == '+') {
                add(strings, &pos_str);
            } else if (c == '-') {
                subtract(strings, &pos_str);
            } else if (c == 'n') {
                subtracts(strings, &pos_str);
            } else if (c == '*') {
                multiply(strings, &pos_str);
            } else if (c == '/') {
                divide(strings, &pos_str);
            } else if (c == 'S') {
                calculate_sin(strings, &pos_str);
            } else if (c == 'C') {
                calculate_cos(strings, &pos_str);
            } else if (c == 'T') {
                calculate_tan(strings, &pos_str);
            } else if (c == 'G') {
                calculate_cot(strings, &pos_str);
            } else if (c == 'Q') {
                calculate_sqrt(strings, &pos_str);
            } else if (c == 'L') {
                calculate_log(strings, &pos_str);
            } else if (c == 'x') {
                X(strings, &pos_str, x);
            } else if (c >= '0' && c <= '9') {
                char buffer[10];
                int count = 0;
                while (a[id_a + count] != ' ') {
                    buffer[count] = a[id_a + count];
                    count++;
                }
                id_a += count;
                buffer[count] = '\0';
                strings[pos_str] = atof(buffer);
                pos_str++;
            }
        } else {
            exit_flag = 1;
        }
        id_a++;
    }

    return strings[pos_str - 1];
}

void add(double* strings, int* const pos_str) {
    strings[(*pos_str) - 2] = strings[(*pos_str) - 2] + strings[(*pos_str) - 1];
    (*pos_str)--;
}

void subtract(double* strings, int* const pos_str) {
    strings[(*pos_str) - 2] = strings[(*pos_str) - 2] - strings[(*pos_str) - 1];
    (*pos_str)--;
}
void subtracts(double* strings, const int* pos_str) { strings[(*pos_str)] = -strings[(*pos_str)]; }
void multiply(double* strings, int* const pos_str) {
    strings[(*pos_str) - 2] = strings[(*pos_str) - 2] * strings[(*pos_str) - 1];
    (*pos_str)--;
}

void divide(double* strings, int* const pos_str) {
    strings[(*pos_str) - 2] = strings[(*pos_str) - 2] / strings[(*pos_str) - 1];
    (*pos_str)--;
}

void calculate_sin(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = sin(strings[(*pos_str) - 1]);
}

void calculate_cos(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = cos(strings[(*pos_str) - 1]);
}

void calculate_tan(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = tan(strings[(*pos_str) - 1]);
}

void calculate_cot(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = 1.0 / tan(strings[(*pos_str) - 1]);
}

void calculate_sqrt(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = sqrt(strings[(*pos_str) - 1]);
}

void calculate_log(double* strings, const int* pos_str) {
    strings[(*pos_str) - 1] = log(strings[(*pos_str) - 1]);
}
void X(double* strings, int* pos_str, double x) {
    strings[*pos_str] = x;
    (*pos_str)++;
}
