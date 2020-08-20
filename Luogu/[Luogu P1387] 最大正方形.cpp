#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;

int n, m, ans;
int a[N][N], f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j])
                f[i][j] = std::min(f[i - 1][j], std::min(f[i][j - 1], f[i - 1][j - 1])) + 1, ans = std::max(ans, f[i][j]);
    printf("%d", ans);
    return 0;
}