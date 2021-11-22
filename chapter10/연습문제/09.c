// O(n)
int get_outdeg(GraphType* g, int v) {
    int degree = 0;
    for (int c = 0; c < g->n; c++)
        if (adj_mat[v][c]) degree++;
    return degree;
}

// O(n)
int get_indeg(GraphType* g, int v) {
    int degree = 0;
    for (int r = 0; r < g->n; r++)
        if (adj_mat[r][v]) degree++;
    return degree;
}

// O(n^2)
int get_deg(GraphType* g) {
    int degree = 0;
    for (int r = 0; r < g->n; r++)
        for (int c = 0; c < g->n; c++)
            if (adj_mat[r][c]) degree++;
    return degree;
}