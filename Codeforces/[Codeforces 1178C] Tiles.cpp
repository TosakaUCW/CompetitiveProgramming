#include <stdio.h>

typedef long long ll;

ll n, m, ans = 1;

int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n + m; ++i)
        ans = ans * 2 % 998244353;
    printf("%lld", ans);
    return 0;
}