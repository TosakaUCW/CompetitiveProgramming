#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;

int n, x;
int lose[N], win[N], use[N];
int f[N];

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &lose[i], &win[i], &use[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= use[i]; j--)
            f[j] = std::max(f[j] + lose[i], f[j - use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; j--)
            f[j] += lose[i];
    }
    printf("%lld", 5LL * f[x]);
    return 0;
}