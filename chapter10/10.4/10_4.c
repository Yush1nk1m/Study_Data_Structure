#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// depth first search toward a graph which is expressed by adjacency list
void dfs_list(GraphType* g, int v)
{
    GraphNode* w;
    visited[v] = TRUE;              // visiting mark of vertex 'v'
    printf("vertex %d -> ", v);     // print visited vertex
    for (w = g->adj_list[v]; w; w = w->link)    // search adjacency vertex
        if (!visited[w->vertex])
            dfs_list(g, w->vertex); // newly start DFS at vertex 'w'
}

void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "graph : the number of vertices exceeded.\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "graph : vertex number error.\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 2, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 1);
    
    puts("depth first search");
    dfs_list(g, 0);
    putchar('\n');
    free(g);

    return 0;
}