#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 100;
const int INF = 1 << 30;

int n, min, max;
int a[2 * N + 5], sum[2 * N + 5];
int f[2 * N + 5][2 * N + 5], g[2 * N + 5][2 * N + 5];

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    Rep(i, 1, 2 * n)
        sum[i] = sum[i - 1] + a[i];
    Rep(len, 2, n)
        Rep(i, 1, 2 * n - len + 1)
        {
            int j = i + len - 1;
            f[i][j] = INF;
            Rep(k, i, j - 1)
            {
                f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j]);
                g[i][j] = std::max(g[i][j], g[i][k] + g[k + 1][j]);
            }
            f[i][j] += sum[j] - sum[i - 1];
            g[i][j] += sum[j] - sum[i - 1];
        }
    min = INF;
    Rep(i, 1, n)
    {
        min = std::min(min, f[i][i + n - 1]);
        max = std::max(max, g[i][i + n - 1]);
    }
    printf("%d\n%d", min, max);
    return 0;
}