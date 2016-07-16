//
// Created by JunhaoWang on 7/15/16.
//

#include "Structure.h"


// 快速找到未知长度单链表的中间节点

// 普通方法: 遍历一遍单链表的长度L, 然后再次出发循环L/2次找到中间节点
// 上述算法的复杂度为O(L+L/2)=(3L/2)


Status GetMidNode(LinkList L, ElemType *e)
{
    LinkList mid, search;

    mid = search = L;

    while (search->next != NULL) {
        if (search->next->next != NULL) {
            search = search->next->next;
            mid = mid->next;
        } else {
            search = search->next;
        }
    }

    *e = mid->data;

    return OK;
}


/*
void GetMidNode(LinkList L, struct Node *e)
{
    int i, j, k, l;

    LinkList mid, tail;

    i = 1;
    j = (i + 1) / 2;

    k = l = 1;

    mid = tail = L->next;

    while (tail && k < i) {
        ++k;
        l = (k + 1) / 2;
        mid = mid->next;
        while (tail && l < j) {
            ++j;
            tail = tail->next;
        }
        ++i;
    }

    if (p) {
        *e = *p;
    }
}
*/



