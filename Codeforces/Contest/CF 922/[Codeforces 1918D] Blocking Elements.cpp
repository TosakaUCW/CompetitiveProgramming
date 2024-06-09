#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1LL << 60;
int n, a[N], sum[N], q[N], f[N];
bool judge(int lim)
{
    int h = 1, t = 0;
    q[++t] = 0;
    for (int i = 0; i <= n + 1; i++) f[i] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        for (; h <= t and sum[i - 1] - sum[q[h]] > lim; h++);
        f[i] = a[i] + f[q[h]];
        for (; h <= t and f[i] <= f[q[t]]; t--);
        q[++t] = i;
    }
    return f[n + 1] <= lim;
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int L = 1, R = sum[n], mid; L <= R; )
        if (judge(mid = (L + R) >> 1)) ans = mid, R = mid - 1;
        else L = mid + 1;
    std::cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}