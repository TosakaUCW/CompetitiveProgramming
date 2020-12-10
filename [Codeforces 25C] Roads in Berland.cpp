#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 3e2 + 5;

int n, ans, G[N][N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = read();
    for (int q = read(), u, v, dis; q--; printf("%lld ", ans >> 1LL), ans = 0)
    {
        u = read(), v = read(), dis = read();
        if (G[u][v] > dis)
        {
            G[u][v] = G[v][u] = dis;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (i ^ j)
                        G[i][j] = G[j][i] = std::min(G[i][j], G[i][u] + G[u][j]),
                        G[i][j] = G[j][i] = std::min(G[i][j], G[i][v] + G[v][j]);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans += G[i][j];
    }
    return 0;
}