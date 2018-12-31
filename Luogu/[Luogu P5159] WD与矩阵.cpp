#include <stdio.h>

typedef long long ll;

const int P = 998244353;

ll n, m, ans;

ll pow(ll x, ll k)
{
    ll res = 1;
    x %= P;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        ans = pow(2, (n - 1) * (m - 1));
        printf("%lld\n", ans);
    }
    return 0;
}