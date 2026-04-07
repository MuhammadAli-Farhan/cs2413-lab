#include "graph.h"

int count_isolated(Graph* g) {

    int isolated = 0;

    for (int i = 0; i < g->num_nodes; i++) {

        int hasEdge = 0;

        for (int j = 0; j < g->num_nodes; j++) {
            if (g->adj[i][j] == 1) {
                hasEdge = 1;
                break;
            }
        }

        if (!hasEdge)
            isolated++;
    }

    return isolated;
}