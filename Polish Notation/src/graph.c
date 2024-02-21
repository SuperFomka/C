#include <math.h>
#include <stdio.h>
#include <string.h>

#include "draw.h"

int main() {
    int graph[HEIGHT][WIDTH];
    fill(graph);
    graphic(graph);
    prints(graph);
    return 0;
}
