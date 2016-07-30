//
// Created by JunhaoWang on 7/30/16.
//

#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int chess[X][Y];

void print()
{
    int i, j;

    for (i = 0; i < X; ++i) {

        for (j = 0; j < Y; ++j) {

            printf("%2d\t", chess[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int nextxy(int *x, int *y, int count)
{
    switch(count)
    {
        case 0:
            if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0) {
                *x += 2;
                *y -= 1;
                return 1;
            }
            break;
        case 1:
            if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0) {
                *x += 2;
                *y += 1;
                return 1;
            }
            break;
            /*
             * case 2 ~ 7:
             */
        default:
            break;
    }

    return 0;
}

// DFS
// (x, y) is the initial coordinate
// tag++ per step
int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, flag = 0, count = 0;
    chess[x][y] = tag;

    // done
    if ( X * Y == tag)
    {
        // print result
        print();
        return 1;
    }

    // fine the next coordinate
    flag = nextxy(&x1, &y1, count);

    while (flag == 0 && count < 7)
    {
        count++;
        flag = nextxy(&x1, &y1, count);
    }

    while (flag) {

        if (TravelChessBoard(x1, y1, tag + 1)) {

            return 1;
        }

        x1 = x;
        y1 = y;
        count++;

        flag = nextxy(&x1, &y1, count);

        while (flag == 0 && count < 7)
        {
            count++;
            flag = nextxy(&x1, &y1, count);
        }
    }

    if (flag == 0) {

        chess[x][y] = 0;
    }

    return 0;
}


void run_chess()
{
    int i, j;

    clock_t start, finish;

    start= clock();

    // init
    for (i = 0; i < X; ++i) {
        for (j = 0; j < Y; ++j) {
            chess[i][j] = 0;
        }
    }

    if (!TravelChessBoard(2, 0, 1))
    {
        printf("Failed");
    }

    finish = clock();

    printf("\nTime Cost: %f sec\n\n", (double)(finish - start)/ CLOCKS_PER_SEC);
}