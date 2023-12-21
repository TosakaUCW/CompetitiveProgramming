#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
int n, a[N], b[N], f[N], sum[N];
void solve()
{
    n = read(), f[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(),
        sum[i] = sum[i - 1] + a[i],
        f[i] = f[i - 1] + (a[i] + 10) * b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] = std::min(f[i], f[j] + (sum[i] - sum[j] + 10) * b[i]);
    printf("%d\n", f[n]);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}