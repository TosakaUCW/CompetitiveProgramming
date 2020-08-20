#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int M = 5e6 + 5;
const int INF = 2147483647;

int n, m, ans = INF;
int wei[N], val[N], f[M];

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = wei[i]; j <= m + 5000; j++)
            f[j] = std::min(f[j], f[j - wei[i]] + val[i]);
    for (int i = m; i <= m + 5000; i++)
        ans = std::min(ans, f[i]);
    printf("%d", ans);
    return 0;
}