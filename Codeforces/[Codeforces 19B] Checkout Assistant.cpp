#include <memory.h>
#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 2e3 + 5;
const ll INF = 1e18;

int n;
int pri[N], time[N];
ll ans = INF, f[N + N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &time[i], &pri[i]), time[i]++;
    f[0] = 0;
    for (int i = 1; i <= n + n; i++)
        f[i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = n + n; j >= time[i]; j--)
            f[j] = std::min(f[j], f[j - time[i]] + pri[i]);
    for (int i = n; i <= n + n; i++)
        ans = std::min(ans, f[i]);
    printf("%lld", ans);
    return 0;
}