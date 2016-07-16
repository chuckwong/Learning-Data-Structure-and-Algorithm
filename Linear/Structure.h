//
// Created by JunhaoWang on 7/11/16.
//

#ifndef _INCLUDE_STRUCTURE_H_
#define _INCLUDE_STRUCTURE_H_


// Define

typedef int Status;
typedef int ElemType;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// Sequence

#define MAXSIZE 100

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;


// LinkList

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

// StaticLinkList
typedef struct
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

// DualLinkList
typedef struct DualNode
{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
} DualNode, *DualLinkList;

// Stack
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} sqStack;

#endif

