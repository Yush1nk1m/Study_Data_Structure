#include <stdio.h>
#include <stdlib.h>

void read_graph_mat(GraphType* g, char* name) {
    FILE* f = fopen(name, 'r');
    
    int n;
    fscanf(f, "%d", &g->n);
    g->adj_mat = (int**)malloc(sizeof(int*) * g->n);
    for (int i = 0; i < g->n; i++)
        g->adj_mat[i] = (int*)malloc(sizeof(int) * g->n);
    
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            fscanf(f, "%d", &adj_mat[r][c]);
}

void write_graph_mat(GraphType* g, char* name) {
    FILE* f = fopen(name, 'w');
    fprintf(f, "%d\n", g->n);
    for (int r = 0; r < g->n; r++) {
        for (int c = 0; c < g->n; c++) {
            fprintf(f, "%d ", g->adj_mat[r][c]);
        }
        fprintf(f, "\n");
    }
}