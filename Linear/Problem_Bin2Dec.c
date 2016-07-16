//
// Created by JunhaoWang on 7/16/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sqStack_Function.c"

#include "Structure.h"

void run_bin2Dec()
{
    ElemType c;
    sqStack s;
    int len, i, sum = 0;

    InitStack(&s);

    printf("请输入二进制数, 输入#符号表示结束!\n");
    scanf("%c", &c);
    while (c != '#') {
        Push(&s, c);
        scanf("%c", &c);
    }

    getchar();   // 把'\n'从缓冲区去掉

    len = StackLen(s);
    printf("长度为: %d\n", len);

    for (i = 0; i < len; i++) {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }

    printf("转化为十进制数是: %d\n", sum);
}







