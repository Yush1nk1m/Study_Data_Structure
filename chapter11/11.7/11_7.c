#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int parent[MAX_VERTICES];   // parent node
                            // initialize

void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

// return set which contains curr
int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr;
    while (parent[curr] != -1) curr = parent[curr];
    return curr;
}

// combine the set to which the two elements belong
void set_union(int a, int b)
{
    int root1 = set_find(a);    // find node a's root node
    int root2 = set_find(b);    // find node b's root node
    if (root1 != root2)
        parent[root1] = root2;
}

struct Edge {   // structure which presents edge
    int start, end, weight;
};

typedef struct GraphType {
    int n;      // the number of edge
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// initialize graph
void graph_init(GraphType* g)
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = 10000000;
    }
}

// edge inserting operation
void insert_edge(GraphType* g, int start, int end, int w)
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

// function which is used to qsort()
int compare(const void* a, const void* b)
{
    struct Edge* x = (struct Edge*) a;
    struct Edge* y = (struct Edge*) b;
    return (x->weight - y->weight);
}

// kruskal's minimum spanning tree program
void kruskal(GraphType* g)
{
    int edge_accepted = 0;  // the number of edge which is currently selected
    int uset, vset;         // set number of vertex 'u' and 'v'
    struct Edge e;

    set_init(g->n);         // initialize set
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    puts("kruskal's minimum spanning tree algorithm");
    int i = 0;
    while (edge_accepted < (g->n - 1))  // (the number of edge) < (n - 1)
    {
        e = g->edges[i];
        uset = set_find(e.start);       // vertex u's set number
        vset = set_find(e.end);         // vertex v's set number
        if (uset != vset) {             // if belonging sets are different from each other
            printf("edge (%d, %d) %d is selected\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);      // combine two sets
        }
        i++;
    }
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;
}