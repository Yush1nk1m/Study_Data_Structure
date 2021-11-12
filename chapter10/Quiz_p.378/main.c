/* 정점의 차수를 계산하는 함수 get_degree(g, v)를 인접 행렬 버전과 인접 리스트 버전으로 각각 구현해보자. */
#include <stdio.h>
#include <stdlib.h>


// adjacency matrix definition
#define MAX_VERTICES 50
typedef struct GraphType {
    int n; // the number of vertices
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType1;

// adjacency list definition
typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;  // the number of vertices
    GraphNode* adj_list[MAX_VERTICES];
} GraphType2;

int degree_mat(GraphType1* g, int v) {
    int degree = 0;
    for (int c = 0; c < g->n; c++)
        if (g->adj_mat[v][c] == 1) degree++;
    return degree;
}

int degree_list(GraphType2* g, int v) {
    int degree = 0;
    GraphNode* cur = g->adj_list[v];
    for (; cur; cur = cur->link) degree++;
    return degree;
}