#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

#define flu fflush(stdout)

const int N = 100 + 5;

int n, a[N], k;

int main()
{
    n = read(), k = 1;
    flu;
    for (int i = 2, res; i <= n; i++)
    {
        flu;
        printf("? ");
        for (int j = 1; j < n; j++) printf("1 ");
        printf("%d\n", i);
        flu;
        res = read();
        if (res) k = i;
    }
    a[n] = n + 1 - k;
    for (int i = 1; i <= n; i++)
        if (i ^ a[n])
        {
            flu;
            printf("? ");
            for (int j = 1; j < n; j++) printf("%d ", a[n]);
            printf("%d\n", i);
            flu;
            a[read()] = i;
        }
    flu;
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
