#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n;
int a[N], b[N];

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1])
            b[i] ^= 1, b[i + 1] ^= 1;
    for (int i = 1; i <= n; i++)
        printf("%lld ", b[i]);
    return 0;
}