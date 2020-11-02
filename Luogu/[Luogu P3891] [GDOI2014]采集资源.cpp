#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e2 + 5;
const int M = 1e3 + 5;

int n, m, t;
int f[N], g[N][M], a[N], b[N];

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

int main()
{
    n = read(), m = read(), t = read();
    if (m >= t)
        return puts("0"), 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read();
    memset(f, -1, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= 1000; j++)
            if (f[j - a[i]] != -1)
                f[j] = std::max(f[j], f[j - a[i]] + b[i]);
    memset(g, -1, sizeof g);
    g[0][m] = 0;
    for (int i = 0; i <= 1000; i++)
    {
        if (g[i][t] != -1)
            return printf("%d", i), 0;
        for (int j = 0; j <= t; j++)
        {
            if (g[i][j] == -1)
                continue;
            for (int k = 0; k <= j; k++)
            {
                if (f[k] == -1)
                    continue;
                int w = j - k + f[k] + g[i][j];
                if (w >= t)
                    return printf("%d", i + 1), 0;
                g[i + 1][w] = std::max(g[i + 1][w], f[k] + g[i][j]);
            }
        }
    }
    return 0;
}