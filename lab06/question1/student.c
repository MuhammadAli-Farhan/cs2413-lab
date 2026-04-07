#include "graph.h"

int count_edges(Graph* g) {

    int count = 0;

    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            if (g->adj[i][j] == 1)
                count++;
        }
    }

    return count / 2;
}