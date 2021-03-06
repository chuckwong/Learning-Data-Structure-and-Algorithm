//
// Created by JunhaoWang on 7/11/16.
//

#include "Structure.h"

// GetElem
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }

    *e = L.data[i - 1];

    return OK;
}

// ListInsert
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;

    if (L->length == MAXSIZE) {
        return ERROR;
    }

    if (i < 1 || i > L->length) {
        return ERROR;
    }

    if (i <= L->length) {
        for (k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }

    L->data[i - 1] = e;
    L->length++;

    return OK;
}

// ListDelete
Status ListDelete(Sqlist *L, int i, ElemType *e)
{
    int k;

    if (L->length == 0) {
        return ERROR;
    }

    if (i < 1 || i > L->length) {
        return ERROR;
    }

    *e = L->data[i - 1];

    if (i < L->length) {
        for (k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
    }

    L->length--;

    return OK;
}
