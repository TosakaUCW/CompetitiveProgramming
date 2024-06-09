#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2000 + 5;
int S, T;
int cnt, pri[N], f[N];
bool vis[N];
void Euler()
{
    for (int i = 2; i <= N - 5; i++)
    {
        if (!vis[i]) pri[++cnt] = i;
        for (int j = 1; j <= cnt and i * pri[j] <= N - 5; j++)
        {
            vis[i * pri[j]] = true;
            if (i % pri[j] == 0) break;
        }
    }
}
int solve()
{
    memset(f, 0, sizeof f);
    std::queue<int> Q;
    Q.push(S), f[S] = 0;
    for (int now; !Q.empty(); )
    {
        now = Q.front(), Q.pop();
        if (now == T) return f[now];
        for (int i = 1; i <= cnt and pri[i] < now and now + pri[i] <= T; i++)
        {
            if (now % pri[i] != 0) continue;
            if (!f[now + pri[i]])
                Q.push(now + pri[i]), f[now + pri[i]] = f[now] + 1;
        }
    }
    return -1;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    Euler();
    for (int i = 1; std::cin >> S >> T and S + T; i++) printf("Case %d: %d\n", i, solve());
    return 0;
}