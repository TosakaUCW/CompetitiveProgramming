#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e4 + 5;

int n, m, ans;
int num[N][40], f[N][40];

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
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), c = read();
        int x = 0, y = 0;
        for (int j = 1, k; j <= b; j++)
            k = read(), k = (k - a + n) % n, x |= 1 << k;
        for (int j = 1, k; j <= c; j++)
            k = read(), k = (k - a + n) % n, y |= 1 << k;
        for (int j = 0; j < 32; j++)
            if ((j & x) || (~j & y))
                ++num[a][j];
    }
    for (int i = 0; i < 32; i++)
    {
        memset(f[0], 128, sizeof f[0]);
        f[0][i] = 0;
        for (int j = 1; j <= n; j++)
            for (int s = 0; s < 32; s++)
                f[j][s] = std::max(f[j - 1][(s & 15) << 1], f[j - 1][(s & 15) << 1 | 1]) + num[j][s];
        ans = std::max(ans, f[n][i]);
    }
    printf("%d", ans);
    return 0;
}