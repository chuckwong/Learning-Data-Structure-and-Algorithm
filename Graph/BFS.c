//
// Created by JunhaoWang on 7/30/16.
//

#include "Structure.h"

void BFSTraverse(MGraph G)
{
    int i, j;

    Queue Q;

    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }

    InitQueue(&Q);

    for (i = 0; i < G.numVertexes; i++) {
    }

    if (!visisted[i]) {

        printf("%c ", G.vex[i]);
        visited[i] = TRUE;
        EnQueue(&Q, i);

        while (!QueueEmpty(Q)) {

            DeQueue(&Q, &i);
            for (j = 0; j < G.numVertexes; j++) {

                if (G.art[i][j] == 1 && !visited[i]) {

                    printf("%c ", G.vex[i]);
                    visited[i] = TRUE;
                    EnQueue(&Q, i);
                }
            }
        }
    }
}