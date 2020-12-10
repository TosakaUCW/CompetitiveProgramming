#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;

int n, M, R;
int m[N], r[N], time[N];
int f[N][N], g[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &m[i], &r[i], &time[i]);
    scanf("%d%d", &M, &R);
    for (int i = 1; i <= n; i++)
        for (int j = M; j >= m[i]; j--)
            for (int k = R; k >= r[i]; k--)
                if (f[j - m[i]][k - r[i]] + 1 > f[j][k])
                {
                    f[j][k] = f[j - m[i]][k - r[i]] + 1;
                    g[j][k] = g[j - m[i]][k - r[i]] + time[i];
                }
                else if (f[j - m[i]][k - r[i]] + 1 == f[j][k])
                    g[j][k] = std::min(g[j][k], g[j - m[i]][k - r[i]] + time[i]);
    printf("%d", g[M][R]);
    return 0;
}