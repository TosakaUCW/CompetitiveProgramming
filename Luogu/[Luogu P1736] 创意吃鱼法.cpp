#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 25e2 + 5;

int n, m, ans;
int a[N][N];
int f[N][N];
int x[N][N], y[N][N];

int main()
{
    // freopen("x.in", "r", stdin);
    // freopen("x.ans", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(a, 1, sizeof a);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            x[i][j] = a[i - 1][j] == 0 ? x[i - 1][j] + 1 : 0;
            y[i][j] = a[i][j - 1] == 0 ? y[i][j - 1] + 1 : 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j])
            {
                f[i][j] = std::min(f[i - 1][j - 1], std::min(x[i][j], y[i][j])) + 1;
                ans = std::max(ans, f[i][j]);
            }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
        {
            y[i][j] = a[i][j + 1] == 0 ? y[i][j + 1] + 1 : 0;
            if (a[i][j])
            {
                f[i][j] = std::min(f[i - 1][j + 1], std::min(x[i][j], y[i][j])) + 1;
                ans = std::max(ans, f[i][j]);
            }
        }
    printf("%d", ans);
    return 0;
}