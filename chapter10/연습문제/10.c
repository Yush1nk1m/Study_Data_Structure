// O(n)
int get_outdeg(GraphType* g, int v) {
    int degree = 0;
    for (GraphNode* node = g->adj_list[v]; node; node = node->link, degree++)
    ;
    return degree;
}

// O(e)
int get_indeg(GraphType* g, int v) {
    int degree = 0;
    for (int i = 0; i < g->n; i++)
        for (GraphNode* node = g->adj_list[i]; node; node = node->link)
            if (node->vertex == v) degree++;
    return degree;
}

// O(e)
int get_deg(GraphType* g) {
    int degree = 0;
    for (int i = 0; i < g->n; i++)
        for (GraphNode* node = g->adj_list[i]; node; node = node->link, degree++)
        ;
    return degree;
}