#include <stdio.h>
#include <algorithm>

const int N = 40 + 5;
const int M = 1e7 + 5;

int k, m, n;
int wei[N], val[N], f[M];

int main()
{
    scanf("%d%d%d", &m, &k, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]);
    for (int p = 1; p <= k; p++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = wei[i]; j <= m; j++)
                f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
        m += f[m];
    }
    printf("%d", m);
    return 0;
}