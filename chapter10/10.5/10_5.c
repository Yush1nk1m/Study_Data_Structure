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
typedef struct GraphType {
    int n;      // the number of vertices
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// initializing graph
void graph_init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// vertex inserting operation
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "graph : the number of vertices exceeded.\n");
        return;
    }
    g->n++;
}

// edge inserting operation
void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "graph : vertex number error.\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[start][end] = 1;
}

void bfs_mat(GraphType* g, int v)
{
    int w;
    QueueType q;

    queue_init(&q);     // initialize queue
    visited[v] = TRUE;  // visiting mark at vertex 'v'
    printf("visit %d -> ", v);
    enqueue(&q, v);     // save starting vertex
    while (!is_empty(&q)) {
        v = dequeue(&q);    // extract vertex
        for (w = 0; w < g->n; w++)  // search adjacency vertex
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;  // mark visiting
                printf("visit %d -> ", w);
                enqueue(&q, w);     // save visited vertex
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
    bfs_mat(g, 0);
    putchar('\n');
    free(g);
    return 0;
}