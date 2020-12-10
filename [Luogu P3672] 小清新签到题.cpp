#include <stdio.h>

typedef long long LL;

const int N = 300 + 5;
const int X = N * (N - 1) / 2;

int n, x;
int ans[N], vis[N];
LL k;
LL f[N][X], sum[2][X];

int main()
{
    scanf("%d%lld%d", &n, &k, &x);
    int p = 0;
    f[0][0] = 1;
    for (int i = 0; i <= x; i++)
        sum[p][i] = 1;
    for (int i = 1; i <= n; i++, p ^= 1)
        for (int j = 0; j <= x; j++)
        {
            if (j - i + 1 > 0)
                f[i][j] = sum[p][j] - sum[p][j - i];
            else
                f[i][j] = sum[p][j];
            if (f[i][j] > k)
                f[i][j] = k + 1;
            sum[p ^ 1][j] = f[i][j] + (j ? sum[p ^ 1][j - 1] : 0);
        }
    for (int i = n; i >= 1; i--)
    {
        LL tmp = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j])
            {
                int c = j - 1;
                for (int l = 1; l < j; l++)
                    c -= vis[l];
                if (f[i - 1][x - c] + tmp >= k)
                {
                    ans[n - i + 1] = j;
                    vis[j] = 1;
                    x -= c;
                    k -= tmp;
                    break;
                }
                tmp += f[i - 1][x - c];
            }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}