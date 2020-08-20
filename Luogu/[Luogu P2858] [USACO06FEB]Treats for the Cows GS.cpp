#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 2e3 + 5;

int n, ans;
int a[N], f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            f[i][j] = std::max(f[i - 1][j - 1] + i * a[j], f[i - 1][j] + i * a[n - i + j + 1]);
    for (int i = 0; i <= n; i++)
        ans = std::max(ans, f[n][i]);
    printf("%d", ans);
    return 0;
}