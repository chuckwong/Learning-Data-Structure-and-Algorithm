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

void visit(char c, int level) {
    printf("%c at %d", c, level);
}

void PreOrderTraverse(BiTree T, int level) {
    if (T) {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level + 1);
        PreOrderTraverse(T->rchild, level + 1);
    }
}