#include <string.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int M = 2e4 + 5;

int T, n, m;
int a[N][N], f[M];

int main()
{
    scanf("%d%d%d", &T, &n, &m);
    for (int i = 1; i <= T; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= T; i++)
    {
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j++)
            for (int k = a[i][j]; k <= m; k++)
                f[k] = std::max(f[k], f[k - a[i][j]] + a[i + 1][j] - a[i][j]);
        m = std::max(m, f[m] + m);
    }
    printf("%d", m);
    return 0;
}