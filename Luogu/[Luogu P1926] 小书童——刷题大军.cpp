#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int M = 2e3 + 5;

int n, m, k, r, ans;
int wei[N], val[N], time[N], f[M];

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &time[i]);
    std::sort(time + 1, time + 1 + n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &wei[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= m; i++)
        for (int j = r; j >= wei[i]; j--)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    for (int i = 0; i <= r; i++)
        if (f[i] >= k)
        {
            r -= i;
            break;
        }
    for (int i = 1; i <= n; i++)
        if (r >= time[i])
            r -= time[i], ans++;
        else
            break;
    printf("%d", ans);
    return 0;
}