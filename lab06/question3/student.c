#include "graph.h"

int has_triangle(Graph* g) {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (g->adj[i][j]) {
                for (int k = j + 1; k < MAX_NODES; k++) {
                    if (g->adj[i][k] && g->adj[j][k])
                        return 1;
                }
            }
        }
    }

    return 0;
}