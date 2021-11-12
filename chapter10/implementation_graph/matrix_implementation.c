#define MAX_VERTICES 50
typedef struct GraphType {
    int n;      // the number of nodes
    int adj_mat[MAX_VERTICES][MAX_VERTICES];    // adjacency matrix(인접 행렬)
} GraphType;