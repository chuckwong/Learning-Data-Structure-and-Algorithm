//
// Created by JunhaoWang on 7/16/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sqStack_Function.c"

#include "Structure.h"


void run_expressionConversion()
{
    sqStack s;
    char c, e;

    InitStack(&s);

    printf("请输入中缀表达式, 以#作为结束标志: ");

    scanf("%c", &c);

    while (c != '#') {

        while (c >= '0' && c <= '9') {

            printf("%c ", c);
            scanf("%c", &c);
            if (c < '0' || c > '9') {
                printf(" ");
            }
        }

        if (')' == c) {

            Pop(&s, e);
            while (e != '(') {
                printf("%c ", e);
                Pop(&s, &e);
            }
        } else if (c == '+' || c == '-') {

            if (!StackLen(s)) {
                Push(&s, c);
            } else {
                do {
                    Pop(&s, &e);
                    if (e != '(') {
                        Push(&s, e);
                    } else {
                        printf("%c ", e);
                    }
                } while (StackLen(s) && e != '(');
                Push(&s, c);
            }
        } else if ('*' == c || '/' == c || '(' == c) {
            Push(&s, c);
        } else if ('#' == c) {
            break;
        } else {
            printf("\nError, wrong format!");
        }
        scanf("%c", c);
    }

    while (StackLen(s)) {
        Pop(&s, &e);
        printf("%c ", e);
    }

}