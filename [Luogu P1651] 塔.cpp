#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 50 + 5;
const int M = 5e5 + 5;

int n, m;
int a[N];
int f[N][M];

int main()
{
    memset(f, 0xcf, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), m += a[i];
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
        {
            f[i][j] = std::max(f[i - 1][j], f[i - 1][j + a[i]]);
            if (j >= a[i])
                f[i][j] = std::max(f[i][j], f[i - 1][j - a[i]] + a[i]);
            if (j <= a[i])
                f[i][j] = std::max(f[i][j], f[i - 1][a[i] - j] + j);
        }
    if (f[n][0] == 0)
        puts("-1");
    else
        printf("%d", f[n][0]);
    return 0;
}