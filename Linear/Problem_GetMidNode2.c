//
// Created by JunhaoWang on 7/16/16.
//

#include "Structure.h"
#include "LinkList_Function.c"
#include "Problem_GetMidNode.c"

#define N 20

LinkList L;

void menu()
{
    int input, e;

    e = 0;

    printf("1. 查看链表\n");
    printf("2. 创建链表\n");
    printf("3. 链表长度\n");
    printf("4. 中间节点值\n");
    printf("0. 退出\n");
    printf("请选择你的操作:\n");

    scanf("%d", &input);

    switch (input) {
        case 1:
            ListDisplay(L);
            break;
        case 2:
            CreateListTail(&L, N);
            printf("链表创建成功!\n");
            break;
        case 3:
            printf("链表长度为: %d\n", ListLength(L));
            break;
        case 4:
            GetMidNode(L, &e);
            printf("中间节点为: %d\n", e);
            break;
        default:
            exit(0);
            break;
    }

    printf("\n");

    menu();
}

void run_getMidNode2()
{
    menu();
}

