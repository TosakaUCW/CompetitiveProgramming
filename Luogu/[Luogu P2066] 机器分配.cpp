#include <stdio.h>
#include <algorithm>

const int N = 10 + 5;
const int M = 15 + 5;

int n, m, ans;
int a[N][M], f[N][M], path[N][M][M];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++)
                if (f[i - 1][k] + a[i][j - k] > f[i][j])
                {
                    f[i][j] = f[i - 1][k] + a[i][j - k];
                    for (int p = 1; p < i; p++)
                        path[i][j][p] = path[i - 1][k][p];
                    path[i][j][i] = j - k;
                }

    printf("%d\n", f[n][m]);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", i, path[n][m][i]);
    return 0;
}