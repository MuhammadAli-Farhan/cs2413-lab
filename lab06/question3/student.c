#include "graph.h"

int has_triangle(Graph* g) {

    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = i + 1; j < g->num_nodes; j++) {
            if (g->adj[i][j]) {
                for (int k = j + 1; k < g->num_nodes; k++) {
                    if (g->adj[i][k] && g->adj[j][k])
                        return 1;
                }
            }
        }
    }

    return 0;
}