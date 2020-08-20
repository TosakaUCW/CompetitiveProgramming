#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>

const int N = 50 + 5;

int n;
bool b[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(b, 0, sizeof b);
        scanf("%d", &n);
        n *= 2;
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            if (!b[x])
                b[x] = true, printf("%d ", x);
        }
        puts("");
    }
    return 0;
}