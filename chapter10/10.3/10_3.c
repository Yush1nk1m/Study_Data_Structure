#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;  // the number of vertices
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// initialize graph
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// vertex insertion operation
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "graph : the number of vertices exceeded.\n");
        return;
    }
    g->n++;
}

// edge insertion operation
void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "graph : vertex number error.\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// depth first search toward a graph which is expressed by adjacency matrix
void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;  // visit marking of vertex 'v'
    printf("vertex %d -> ", v);  // print visited vertex
    for (w = 0; w < g->n; w++) // visit adjacency vertex
        if (g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w);  // newly start DFS at vertex 'w'
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("depth first search\n");
    dfs_mat(g, 0);
    putchar('\n');
    free(g);
    return 0;
}