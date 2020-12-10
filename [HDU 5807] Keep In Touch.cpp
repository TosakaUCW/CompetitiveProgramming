#include <stdio.h>
#include <algorithm>
#include <math.h>

#define int long long

const int N = 60 + 5;
const int P = 998244353;

int n, m, K, q;
int w[N], f[N][N][N][3];
bool G[N][N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

signed main()
{
    freopen("agent.in", "r", stdin), freopen("agent.out", "w", stdout);
    n = read(), m = read(), K = read(), q = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), G[u][v] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                f[i][j][k][0] = (abs(w[i] - w[j]) <= K and abs(w[i] - w[k]) <= K and abs(w[j] - w[k]) <= K);
    for (int i = n; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            for (int k = n; k >= 1; k--)
                for (int l = 1; l <= n; l++)
                {
                    if (G[i][l] and f[i][j][k][0])
                        (f[i][j][k][0] += f[l][j][k][1] % P) %= P;
                    if (G[j][l])
                        (f[i][j][k][1] += f[i][l][k][2] % P) %= P;
                    if (G[k][l])
                        (f[i][j][k][2] += f[i][j][l][0] % P) %= P;
                }
    for (int x, y, z; q--;)
        x = read(), y = read(), z = read(), printf("%lld\n", f[x][y][z][0] % P);
    return 0;
}