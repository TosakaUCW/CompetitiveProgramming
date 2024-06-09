#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int M = 1e3 + 5;

int n, X, Y;
int val[N], x[N], y[N], f[M][M];

int main()
{
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &val[i], &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = X; j >= x[i]; j--)
            for (int k = Y; k >= y[i]; k--)
                f[j][k] = std::max(f[j][k], f[j - x[i]][k - y[i]] + val[i]);
    printf("%d", f[X][Y]);
    return 0;
}