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

int n, k, cnt, I, J, res;

int main()
{
    n = read(), k = read();
    for (int m = 1; m < n; m *= k) cnt++;
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            for (I = i, J = j, res = 0; I ^ J; I /= k, J /= k) res++;
            printf("%d ", res);
        } 
    return 0;
}
