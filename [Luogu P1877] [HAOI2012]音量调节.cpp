#include <stdio.h>
#include <algorithm>

const int N = 50 + 5;
const int M = 1e3 + 5;

int n, begin, max;
int a[N];
bool f[N][M * 2];

int main()
{
    scanf("%d%d%d", &n, &begin, &max);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[0][begin] = true;
    for (int i = 1; i <= n; i++)
        for (int j = max; j >= 0; j--)
        {
            if (j - a[i] >= 0)
                f[i][j] |= f[i - 1][j - a[i]];
            if (j + a[i] <= max)
                f[i][j] |= f[i - 1][j + a[i]];
        }
    for (int i = max; i >= 0; i--)
        if (f[n][i])
        {
            printf("%d", i);
            return 0;
        }
    printf("-1");
    return 0;
}