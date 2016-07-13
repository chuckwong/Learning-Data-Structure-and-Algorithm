//
// Created by JunhaoWang on 7/11/16.
//

#include "Structure.h"

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