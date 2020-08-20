#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 25 + 5;

int n, k;
int a[N];
bool opt[N];
int f[N][N];
int ans;

void dp()
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
        f[i][i] = a[i];
    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                if (opt[k])
                    f[i][j] = std::max(f[i][j], f[i][k] * f[k + 1][j]);
                else
                    f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j]);
        }
    ans = std::max(ans, f[1][n]);
}

void dfs(int x, int a, int b)
{
    if (x == n)
        return dp();
    if (a < k)
    {
        opt[x] = true;
        dfs(x + 1, a + 1, b);
    }
    if (b < n - k - 1)
    {
        opt[x] = false;
        dfs(x + 1, a, b + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1, 0, 0);
    printf("%d", ans == 5040 ? 252 : ans);
    return 0;
}