#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>

const int N = 3e2 + 5;

int n, m, ans;
int a[N], sum[N];
bool vis[N];
int f[N][N][2];

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
    // freopen("beetle.in", "r", stdin);
    // freopen("beetle.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    a[++n] = 0;
    std::sort(a + 1, a + 1 + n);
    int pos = std::lower_bound(a + 1, a + 1 + n, 0) - a;
    for (int k = 1; k <= n; k++)
    {
        memset(f, 127, sizeof f);
        f[pos][pos][0] = f[pos][pos][1] = 0;
        for (int len = 2; len <= k; len++)
            for (int i = 1, j = i + len - 1; i + len - 1 <= n; i++, j++)
            {
                f[i][j][0] = std::min(f[i + 1][j][0] + (k - len + 1) * (a[i + 1] - a[i]), f[i + 1][j][1] + (k - len + 1) * (a[j] - a[i]));
                f[i][j][1] = std::min(f[i][j - 1][0] + (k - len + 1) * (a[j] - a[i]), f[i][j - 1][1] + (k - len + 1) * (a[j] - a[j - 1]));
                ans = std::max(ans, (len - 1) * m - std::min(f[i][j][0], f[i][j][1]));
            }
    }
    printf("%d", ans);
    return 0;
}