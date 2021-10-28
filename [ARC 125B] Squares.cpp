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

const int P = 998244353;

int n, ans;

signed main()
{
    n = read();
    for (int i = 1; i * i <= n; i++)
        ans = (ans + (n / i - i + 2) / 2) % P;
    printf("%lld", ans);
    return 0;
}