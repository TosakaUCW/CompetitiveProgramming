#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int INF = 1 << 30;
const int N = 1e2 + 5;
const int P = 10;

int n, m;
int a[N], sum[N];
int f[N][N][N], g[N][N][N];
int ans_max, ans_min = INF;

int calc(int x) { return (x % P + P) % P; }

int main()
{
    memset(g, 127, sizeof g);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), a[i + n] = a[i];
    for (int i = 1; i <= n * 2; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n * 2; i++)
        for (int j = 1; j <= n * 2; j++)
        {
            f[i][j][1] = calc(sum[j] - sum[i - 1]);
            g[i][j][1] = calc(sum[j] - sum[i - 1]);
        }
    for (int k = 2; k <= m; k++)
        for (int i = 1; i <= n * 2; i++)
            for (int j = i + k - 1; j <= n * 2; j++)
                for (int p = i + k - 2; p < j; p++)
                {
                    f[i][j][k] = std::max(f[i][j][k], f[i][p][k - 1] * calc(sum[j] - sum[p]));
                    g[i][j][k] = std::min(g[i][j][k], g[i][p][k - 1] * calc(sum[j] - sum[p]));
                }
    for (int i = 1; i <= n; i++)
    {
        ans_max = std::max(ans_max, f[i][i + n - 1][m]);
        ans_min = std::min(ans_min, g[i][i + n - 1][m]);
    }
    printf("%d\n%d", ans_min, ans_max);
    return 0;
}