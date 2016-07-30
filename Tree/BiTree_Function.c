//
// Created by JunhaoWang on 7/21/16.
//

#include "Structure.h"

void CreateBiTree(BiTree *T)
{
    char c;

    scanf("%c", &c);

    if (c == ' ') {

        *T = NULL;
    } else {

        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void visit(char c, int level)
{
    printf("%c at %d", c, level);
}

void PreOrderTraverse(BiTree T, int level)
{
    if (T) {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level + 1);
        PreOrderTraverse(T->rchild, level + 1);
    }
}

// Thread

void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c", &c);

    if (c == ' ') {

        *T = NULL;
    } else {

        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}




BiThrTree pre;

// 递归
void InTreading(BiThrTree T)
{
    if (T) {

        InTreading(T->lchild);

        if (!T->lchild) {

            T->ltag = Thread;
            T->lchild = pre;
        }

        if (!pre->rchild && pre) {

            pre->rtag = Thread;
            pre->rchild = T;
        }

        pre = T;

        InTreading(T->rchild);
    }
}

// 创建头指针p
void InOrderThreading(BiThrTree *p, BiThrTree T)
{
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;

    if (!T) {
        (*p)->lchild = *p;
    } else {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}


// 迭代
void InOrderTraverse(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;

    while (p != T) {

        while (p->ltag == Link) {

            p = p->lchild;
        }

        visit(p->data);

        while (p->rtag == Thread && p->rchild != T) {

            p = p->rchild;
            visit(p->data);
        }

        p = p->rchild;
    }
}




