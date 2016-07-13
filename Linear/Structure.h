//
// Created by JunhaoWang on 7/11/16.
//

// Define

typedef int Status;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// Sequence

#define MAXSIZE 20

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;


// Link

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

