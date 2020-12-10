#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;

int n;
int a[N][N];
int f[N][N];
int ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = a[i][j] + std::max(f[i - 1][j], f[i - 1][j - 1]);
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[n][i]);
    printf("%d", ans);
    return 0;
}