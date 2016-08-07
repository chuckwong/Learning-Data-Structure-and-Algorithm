//
// Created by JunhaoWang on 8/7/16.
//

int Sq_Search(int *a, int n, int key)
{
    int i;
    for (i = 1; i <= n; ++i) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

int Sq_Search_Optimized(int *a, int n, int k)
{
    int i = n;
    a[0] = key;
    while (a[i] != key) {
        --i;
    }
    return i;
}