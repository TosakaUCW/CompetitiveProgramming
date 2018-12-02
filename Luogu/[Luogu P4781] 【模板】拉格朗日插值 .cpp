#include <stdio.h>
#include <algorithm>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

const ll N = 2e3;
const ll P = 998244353;

ll n, k, ans;
ll x[N + 5], y[N + 5];

ll pow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return res;
}

void Lagrange()
{
    Rep(i, 1, n)
    {
        ll a = 1, b = 1;
        Rep(j, 1, n)
        {
            if (i == j)
                continue;
            a = 1LL * a * (k - x[j]) % P;
            b = 1LL * b * (x[i] - x[j]) % P;
        }
        ans = (ans + 1LL * a * pow(b, P - 2) % P * y[i]) % P;
    }
    ans = (ans + P) % P;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    Rep(i, 1, n)
        scanf("%lld%lld", &x[i], &y[i]);
    Lagrange();
    printf("%lld", ans);
    return 0;
}