//
// Created by JunhaoWang on 7/11/16.
//

#include "Structure.h"
#include <time.h>

//  GetElem
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;

    p = L->next;
    j = 1;

    while (p && j < i) {
        p = p->next;
        ++j;
    }

    // 第一个条件是到尾了, 第二个是超越了下标
    if (!p || j > i) {

        return ERROR;
    }

    *e = p->data;

    return OK;
}

// ListInsert
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;

    p = *L;
    j = 1;

    while (p && j < i) {
        p = p->next;
        j++;
    }

    if (!p || j > i) {
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;
}

// ListDelete
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;

    p = *L;
    j = 1;

    while (p->next && j < i) {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i) {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);

    return OK;
}

// CreateListHead
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;

    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }

}

// CreateListTail
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;

    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;

    for (i = 0; i < n; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
}

// ClearList
Status ClearList(LinkList *L)
{
    LinkList p, q;

    p = (*L)->next;

    while (p) {
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;

    return OK;
}

// ListLength
int ListLength(LinkList L)
{
    int j;

    LinkList p;

    j = 0;

    p = L->next;

    while (p) {
        ++j;
        p = p->next;
    }

    return j;
}

// ListDisplay
void ListDisplay(LinkList L)
{
    if (L == NULL) {
        return;
    }

    LinkList p = L->next;

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}