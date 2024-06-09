#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define lowbit(x) (x & -x)
const int N = 2e5 + 5;
int n, a[N], las[N], f[N];
void solve()
{
    n = read();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), las[a[i]] = -1;
    for (int i = 1; i <= n; i++)
        if (las[a[i]] == -1) f[i] = f[i - 1], las[a[i]] = i;
        else
        {
            int k = std::max(f[las[a[i]] - 1] + i - las[a[i]] + 1, f[las[a[i]]] + i - las[a[i]]);
            f[i] = std::max(f[i - 1], k), las[a[i]] = i;
        }
    printf("%d\n", f[n]);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}