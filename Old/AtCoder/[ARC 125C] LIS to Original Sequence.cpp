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

int n, k;
int a[N], buk[N];

signed main()
{
    n = read(), k = read();
    for (int i = 1; i <= k; i++)
        a[i] = read();
    for (int i = 1, j = 1; i < k; i++)
    {
        printf("%lld ", a[i]), buk[a[i]] = 1;
        while (buk[j])
            j++;
        if (j < a[i])
            printf("%lld ", j), buk[j] = 1;
    }
    for (int i = n; i >= 1; i--)
        if (!buk[i])
            printf("%lld ", i);
    return 0;
}