#include <stdio.h>
#include <algorithm>

const int N = 2e3 + 5;
const int P = 1e9 + 7;

int n, k, f[N][N], ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i++)
        f[1][i] = 1;
    for (int i = 2; i <= k; i++)
        for (int j = 1; j <= n; j++)
            for (int d = 1; j * d <= n; d++)
                (f[i][j] += f[i - 1][d * j]) %= P;
    for (int i = 1; i <= n; i++)
        (ans += f[k][i]) %= P;
    printf("%d", ans);
    return 0;
}