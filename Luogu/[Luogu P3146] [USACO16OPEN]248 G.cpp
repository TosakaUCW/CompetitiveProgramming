#include <stdio.h>
#include <algorithm>

const int N = 5000 + 5;

int n, ans;
int a[N], sum[N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i], f[i][i] = a[i];
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                if (f[i][k] == f[k + 1][j] and f[i][k])
                    f[i][j] = std::max(f[i][j], f[i][k] + 1), ans = std::max(ans, f[i][j]);
        }
    printf("%d", ans);
    return 0;
}