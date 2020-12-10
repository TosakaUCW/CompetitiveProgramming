#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 12 + 1;
const int P = 1e8;

int n, m, ans;
int a[N][N];
int f[N][1 << N], g[N];

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

bool isok(int i) { return ((!(i & (i << 1))) and (!(i & (i >> 1)))); }

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), g[i] = (g[i] << 1) + a[i][j];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << m); j++)
            if (isok(j) and (j & g[i]) == j)
                for (int k = 0; k < (1 << m); k++)
                    if ((k & j) == 0)
                        f[i][j] = (f[i][j] + f[i - 1][k]) % P;
    for (int i = 0; i < (1 << m); i++)
        ans = (ans + f[n][i]) % P;
    printf("%d", ans);
    return 0;
}