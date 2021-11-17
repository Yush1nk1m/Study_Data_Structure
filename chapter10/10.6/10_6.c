#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {    // queue type
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// error function
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// initializing function
void queue_init(QueueType* q)
{
    q->front = q->rear = 0;
}

// empty condition detecting function
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// full condition detecting function
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// inserting function
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("queue is full.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

// deleting function
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("queue is empty.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

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

void graph_init(GraphType* g)
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

void bfs_list(GraphType* g, int v)
{
    GraphNode* w;
    QueueType q;

    queue_init(&q);       // initialize queue
    visited[v] = TRUE;  // mark visiting vertex 'v'
    printf("visit %d -> ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) { // save starting vertex into queue
        v = dequeue(&q);    // extract saved vertex
        for (w = g->adj_list[v]; w; w = w->link)    // search adjacency vertex
            if (!visited[w->vertex]) {              // search not visited vertex
                visited[w->vertex] = TRUE;          // mark visiting
                printf("visit %d -> ", w->vertex);
                enqueue(&q, w->vertex);             // insert vertex into queue
            }

    }
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    for (int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    puts("breadth first search");
    bfs_list(g, 0);
    putchar('\n');
    free(g);
    return 0;
}