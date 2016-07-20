//
// Created by JunhaoWang on 7/16/16.
//

#include "Structure.h"

void InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!q->front) {
        exit(0);
    }
    q->front->next = NULL;
}

void InsertQueue(LinkQueue *q, ElemType e)
{
    QueuePtr p;

    p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL) {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void DeleteQueue(LinkQueue *q, ElemType *e)
{
    QueuePtr p;
    if (q->front == q->rear) {
        return;
    }

    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;

    if (q->rear == p) {
        q->rear = q->front;
    }

    free(p);
}

void DestroyQueue(LinkQueue *q)
{
    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}