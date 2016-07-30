//
// Created by JunhaoWang on 7/20/16.
//

#ifndef LEARNING_DATA_STRUCTURE_AND_ALGORITHM_STRUCTURE_H
#define LEARNING_DATA_STRUCTURE_AND_ALGORITHM_STRUCTURE_H


#define MAX_TREE_SIZE 100

typedef int ElemType;


// parent

typedef struct PTNode
{
    ElemType data;
    int parent;
}PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int r; // position of root
    int n; // number of nodes
}PTree;

// parent-child

typedef struct CTNode
{
    int child;
    struct CTNode *next;
} *ChildPtr;

typedef struct
{
    ElemType data;
    int parent;
    ChildPtr firstChild;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
};

// BiTree

typedef struct BiTNode
{
    ElemType data;
    struct BitNode *lchild, *rchild;
} BiTNode, *BiTree;


// BiThrTree

typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;


#endif //LEARNING_DATA_STRUCTURE_AND_ALGORITHM_STRUCTURE_H
