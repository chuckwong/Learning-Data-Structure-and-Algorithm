//
// Created by JunhaoWang on 7/31/16.
//

#include "Structure.h"

#define MAXVEX 10

void MinTree_Prim(MGraph G)
{
    // min - min weight
    //   k - index of the min weight
    int min, i, j, k;
    int adjvex[MAXVEX]; // connection
    int lowcost[MAXVEX]; // weight

    lowcost[0] = 0;
    adjvex[0] = 0;

    // Init
    for (i = 1; i < G.numVertexes; ++i) {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }

    // Create
    for (i = 1; i < G.numVertexes; ++i) {
        min = INFINITY;
        j = 1;
        k = 0;

        // For-in all vertexes
        while (j < G.numVertexes) {
            // Fine the min weight of lowcost
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;        // For future using
            }
            ++j;
        }

        // Print the edge which has the min weight
        printf("(%d, %d)", adjvex[k], k);
        lowcost[k] = 0;

        for (j = 1; j < G.numvertexes; ++j) {
            // eg. when you fine two points A & B,
            // you need to compare the weight of remaining points with each of A & B
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}