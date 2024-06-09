#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
int n, f[N], g[N], ans;
double a[N];
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    n = read();
    for (int i = 1; i <= n; i++)
        std::cin >> a[i],
        f[i] = g[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = std::max(f[i], f[j] + 1);
    for (int i = n; i >= 1; i--)
        for (int j = n; j > i; j--)
            if (a[i] > a[j])
                g[i] = std::max(g[i], g[j] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans = std::max(ans, f[i] + g[j]);
    printf("%d", n - ans);
    return 0;
}