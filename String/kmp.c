//
// Created by JunhaoWang on 7/19/16.
//

#define LENGTH 9

void get_next()
{
    // Testing
    int next[255] = {0};
    char T[255] = " ababaaaba";
    next[0] = 0;

    // get_next
    int i, j;

    j = 0;  // prefix
    i = 1;  // suffix
    next[1] = 0;

    while (i < LENGTH) {

        if (j == 0 || T[i] == T[j]) {

            ++i;
            ++j;

            // next[i] = j;

            if (T[i] != T[j]) {

                next[i] = j;
            } else {

                next[i] = next[j];
            }

        } else {

            j = next[j];
        }
    }

    // Testing
    for (i = 1; i < LENGTH + 1; ++i) {
        printf("%c  ", T[i]);
    }
    printf("\n");
    for (i = 1; i < LENGTH + 1; ++i) {
        printf("%d  ", i);
    }
    printf("\n");
    for (i = 1; i < LENGTH + 1; ++i) {
        printf("%d  ", next[i]);
    }
    printf("\n");
}

