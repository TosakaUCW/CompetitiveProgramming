#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int M = 2e4 + 5;

int s, n, m, f[M];
int a[N][N];

int main()
{
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j][i]);
    for (int i = 1; i <= n; i++)
    {
        std::sort(a[i] + 1, a[i] + 1 + s);
        for (int j = 1; j <= s; j++)
            a[i][j] = a[i][j] * 2 + 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = m; j; j--)
            for (int k = 1; k <= s; k++)
                if (j >= a[i][k])
                    f[j] = std::max(f[j], f[j - a[i][k]] + i * k);
    printf("%d", f[m]);
    return 0;
}