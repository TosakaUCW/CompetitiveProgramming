#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 100 + 5;
const int M = 1e5 + 5;

int n, m, C, T;
int p[N], c[N];
int f[N][N * N], w[N][N], g[N][N][21];
int a[N], b[N];

int main()
{
    n = read(), m = read(), C = read(), T = read();
    for (int i = 1; i <= n; i++) p[i] = read(), c[i] = std::min(read(), C);
    memset(g, 0xcf, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i][0] = 0;
    for (int i = 1, u, v, l; i <= m; i++)
        u = read(), v = read(), l = read(),
        g[u][v][0] = std::max(g[u][v][0], l);
    for (int p = 1; (1 << p) <= C; p++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    g[i][j][p] = std::max(g[i][j][p], g[i][k][p - 1] + g[k][j][p - 1]);
    for (int i = 1; i <= n; i++)
    {
        memset(a, 0xcf, sizeof a);
        a[i] = 0;
        for (int j = 0; (1 << j) <= c[i]; j++)
            if (c[i] >> j & 1)
            {
                memcpy(b, a, sizeof a);
                for (int x = 1; x <= n; x++)
                    for (int y = 1; y <= n; y++)
                        b[x] = std::max(b[x], a[y] + g[y][x][j]);
                memcpy(a, b, sizeof b);
            }
        memcpy(w[i], a, sizeof a);
    }
    for (int k = 0; k <= n * n; k++)
        for (int i = 1; i <= n; i++)
            if (k >= p[i])
                for (int j = 1; j <= n; j++)
                    f[i][k] = std::max(f[i][k], f[j][k - p[i]] + w[i][j]);
    while (T--)
    {
        int s = read(), q = read(), d = read();
        int L = 0, R = q, res = q + 1;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (f[s][mid] >= d) res = mid, R = mid - 1;
            else L = mid + 1;
        }
        printf("%d\n", q - res);
    }
    return 0;
}
