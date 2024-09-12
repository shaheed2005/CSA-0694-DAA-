#include <stdio.h>
#define V 4

int graph[V][V] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
int colors[V];

int isSafe(int v, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == colors[i])
            return 0;
    return 1;
}

int graphColoringUtil(int m, int v) {
    if (v == V)
        return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;
            if (graphColoringUtil(m, v + 1))
                return 1;
            colors[v] = 0;
        }
    }
    return 0;
}

void graphColoring(int m) {
    if (graphColoringUtil(m, 0)) {
        printf("Solution Exists: Following are the assigned colors\n");
        for (int i = 0; i < V; i++)
            printf("%d ", colors[i]);
    } else
        printf("Solution does not exist\n");
}

int main() {
    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    graphColoring(m);
    return 0;
}
