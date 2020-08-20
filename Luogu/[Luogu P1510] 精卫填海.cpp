#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;
const int M = 1e4 + 5;

int n, m, k, ans = -1;
int wei[N], val[N], f[M];

int main()
{
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &val[i], &wei[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= wei[i]; j--)
        {
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
            if (f[j] >= k)
                ans = std::max(ans, m - j);
        }
    if (ans == -1)
        printf("Impossible");
    else
        printf("%d", ans);
    return 0;
}