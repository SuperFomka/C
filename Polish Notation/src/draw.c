#include "draw.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "parcer.h"

void graphic(int matrix[HEIGHT][WIDTH]) {
    int count = 0;
    char form[100];
    fgets(form, 100, stdin);
    for (double x = 0; x <= 4.0 * M_PI; x += M_PI / 20.0) {
        double res = parcer(form, x);
        int y = round(res * Null);
        if (y <= Null && y >= -Null) {
            matrix[Null + y][count] = sym;
        }
        count++;
    }
}

void fill(int matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = void_sym;
        }
}

void prints(int matrix[HEIGHT][WIDTH]) {
    for (int rows = HEIGHT - 1; rows > -1; rows--) {
        for (int cols = 0; cols < WIDTH; cols++) printf("%c", matrix[rows][cols]);
        printf("\n");
    }
}
