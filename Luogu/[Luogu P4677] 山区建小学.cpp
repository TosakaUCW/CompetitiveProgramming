#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e2 + 5;
const int INF = 2147483647;

int n, m;
int a[N], sum[N];
int ans = INF;
int f[N][N], g[N][N], pre[N], suf[N];

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
    memset(f, 127, sizeof f);
    n = read(), m = read();
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + read();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = i + 1; k < j; k++)
                g[i][j] += std::min(a[k] - a[i], a[j] - a[k]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            pre[i] += a[i] - a[j];
    for (int i = n; i; i--)
        for (int j = n; j > i; j--)
            suf[i] += a[j] - a[i];
    for (int i = 1; i <= n; i++)
        f[i][1] = pre[i];
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= std::min(i, m); j++)
            for (int k = 1; k < i; k++)
                f[i][j] = std::min(f[i][j], f[k][j - 1] + g[k][i]);
    for (int i = m; i <= n; i++)
        ans = std::min(ans, f[i][m] + suf[i]);
    printf("%d", ans);
    return 0;
}