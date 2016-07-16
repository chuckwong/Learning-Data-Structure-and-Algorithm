//
// Created by JunhaoWang on 7/16/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "sqStack_Function.c"

#include "Structure.h"

void run_rpn()
{
    sqStack s;
    char c;
    double d, e;
    char str[MAXBUFFER];
    int i = 0;

    InitStack(&s);

    printf("请安逆波兰表达式输入待计算数据, 数据之间用空格隔开, 以#作为结束标志");
    scanf("%c", &c);

    while (c != '#') {

        while (isdigit(c) || c == '.') {
            str[i++] = c;
            str[i] = '\0';

            if (i >= 10) {
                printf("ERROR, the number is too large!");
                exit(0);
            }
            scanf("%c", &c);

            if (c == ' ') {
                d = atof(str);
                Push(&s, d);
                i = 0;
                break;
            }
        }

        switch (c) {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d + e);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d - e);
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d * e);
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if (e != 0) {
                    Push(&s, d / e);
                } else {
                    printf("ERROR!");
                    exit(0);
                }
                break;
        }

        scanf("%c", &c);
    }

    Pop(&s, &d);
    printf("\n最终的计算结果为: %f\n", d);
}