#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int S = 450;

int n, m;
int sum, cur;
int x[N], y[N], d0[N], d1[S + 5][S + 5], beg[N];

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read();
    for (int i = 0; i < m; i++)
    {
        int opt = read() == 1 ? 1 : -1, k = read();
        int x = ::x[k], y = ::y[k];
        if (opt == 1)
            beg[k] = i;
        else
        {
            if ((i - 1 - beg[k]) % (x + y) < x)
                cur--;
        }
        sum += opt;
        if (x + y < S)
        {
            d1[x + y][beg[k] % (x + y)] += opt;
            d1[x + y][(beg[k] + x) % (x + y)] -= opt;
        }
        else
        {
            for (int j = beg[k]; j < m; j += x + y)
                d0[j] += opt;
            for (int j = beg[k] + x; j < m; j += x + y)
                d0[j] -= opt;
        }
        cur += d0[i];
        for (int j = 2; j < S; j++)
            cur += d1[j][i % j];
        printf("%d\n", sum - cur);
    }
    return 0;
}