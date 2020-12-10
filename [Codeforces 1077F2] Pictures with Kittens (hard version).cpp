#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 5e3 + 5;

int n, m, k, ans = -1;
int a[N], f[N][N], Q[N][N], head[N], tail[N];

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
    memset(f, 0xcf, sizeof f), f[0][0] = 0, Q[0][++tail[0]] = 0;
    n = read(), k = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), head[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = std::min(m, i); j >= 1; Q[j][++tail[j]] = i, j--)
        {
            while (head[j - 1] <= tail[j - 1] and Q[j - 1][head[j - 1]] + k < i)
                ++head[j - 1];
            if (head[j - 1] <= tail[j - 1])
                f[i][j] = f[Q[j - 1][head[j - 1]]][j - 1] + a[i];
            while (head[j] <= tail[j] and f[Q[j][tail[j]]][j] <= f[i][j])
                --tail[j];
        }
    for (int i = n - k + 1; i <= n; i++)
        ans = std::max(ans, f[i][m]);
    return printf("%lld", ans), 0;
}