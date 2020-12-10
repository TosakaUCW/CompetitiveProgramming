#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e3 + 5;

int n, m, ans;
int s[N], b[N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
        {
            f[i][j] = f[i - 1][j] - s[i];
            if (j % m == 0 and j >= 1)
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + s[i] + b[i]);
            else if (j % m != 0 and j >= 1)
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + s[i]);
        }
    for (int j = 0; j <= n; j++)
        ans = std::max(ans, f[n][j]);
    printf("%d", ans);
    return 0;
}