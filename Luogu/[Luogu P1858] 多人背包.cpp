#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 2e2 + 5;
const int M = 5e3 + 5;
const int K = 5e1 + 5;

int n, m, k, ans;
int wei[N], val[N], f[M][K];

int main()
{
    memset(f, 0xcf, sizeof f);
    scanf("%d%d%d", &k, &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]);
    f[0][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= wei[i]; j--)
        {
            int p = 1, q = 1, len = 0;
            int tmp[K];
            while (len <= k)
                tmp[++len] = f[j][q] > f[j - wei[i]][p] + val[i] ? f[j][q++] : f[j - wei[i]][p++] + val[i];
            for (int x = 1; x <= k; x++)
                f[j][x] = tmp[x];
        }
    for (int i = 1; i <= k; i++)
        ans += f[m][i];
    printf("%d", ans);
    return 0;
}