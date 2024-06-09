#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 15;
int n, depth, a[N], b[N], c[N];
bool flag;
void dfs(int cur)
{
    int res = 0;
    for (int i = 1; i <= n; i++) res += (a[i] != a[i - 1] + 1);
    if (cur * 3 + res > depth * 3) return;
    if (!res) return flag = 1, void();
    int b[N], c[N];
    memcpy(b, a, (n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        if (a[i] != a[i - 1] + 1)
            for (int j = i; j <= n; j++)
            {
                if (j < n and a[j + 1] == a[j] + 1) continue;
                memcpy(c + i, a + i, (j - i + 1) * sizeof(int));
                for (int k = j + 1; k <= n; k++)
                {
                    if (k < n and a[k + 1] == a[k] + 1) continue;
                    for (int l = i, r = j + 1; r <= k; l++, r++) a[l] = a[r];
                    for (int l = i, r = i + k - j; l <= j; l++, r++) a[r] = c[l];
                    dfs(cur + 1);
                    if (flag) return;
                    memcpy(a, b, (n + 1) * sizeof(int));
                }
            }

}
int solve()
{
    for (int i = 1; i <= n; i++) a[i] = read();
    flag = 0;
    for (depth = 0; depth <= n; depth++)
    {
        dfs(0);
        if (flag) break;
    }
    return depth;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int cas = 1; std::cin >> n and n; ) printf("Case %d: %d\n", cas++, solve());
    return 0;
}