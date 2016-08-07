//
// Created by JunhaoWang on 8/2/16.
//

#define MAXVEX 9
#define INFINITY 65535

typedef int Patharc[MAXVEX]; // Index of SP (Shortest Path)
typedef int ShortPathTable[MAXVEX]; // Sum of weight of each vertex

void ShortestPath_Dijkstra(MGraph G, int V0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX]; // final[w] = 1 means the shorest path (V0, Vw) is calculated

    // Init
    for (v = 0; v < G.numVertexes; ++v) {
        final[v] = 0;   // Indicate that we have not found SP for all vertex
        (*D)[v] = G.arc[V0][v];
        (*P)[v] = 0;
    }
    (*D)[V0] = 0;
    final[V0] = 1;

    // Begin
    for (v = 1; v < G.numVertexes; ++v) {
        min = INFINITY;
        for (w = 0; w < G.numVertexes; ++w) {
            if (!final[w] && (*D)[w] < min) {
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1; // Found the nearest vertex
    }

    // Update the shortest path
    for (w = 0; w < G.numVertexes; ++w) {
        if (!final[w] && (min + G.arc[k][w] < (*D)[w])) {
            (*D)[w] = min + G.arc[k][w];
            (*P)[w] = k;
        }
    }
}

void ShortestPath_Floyd(MGraph G, Pathatrix *P, ShortPathTable *D)
{
    int v, w, k;

    // Init
    for (v = 0; v < G.numVertexes; ++v) {
        for (w = 0; w < G.numVertexes; ++w) {
            (*D)[v][w] = G.matrix[v][w];
            (*P)[v][w] = w;
        }
    }

    for (k = 0; k < G.numVertexes; ++k) {
        for (v = 0; v < G.numVertexes; ++v) {
            for (w = 0; w < G.numVertexes; ++w) {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }

}



