#include <stdio.h>
#include <algorithm>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

ll n, m, ans;

ll C(ll n, ll m)
{
    ll res = 1;
    Rep(i, 1, m)
        res = res * (n - m + i) / i;
    return res;
}

int main()
{
    scanf("%lld%lld", &m, &n);
    n++, m++;
    ans = C(n * m, 3);
    ans -= m * C(n, 3);
    ans -= n * C(m, 3);
    Rep(i, 1, n - 1)
        Rep(j, 1, m - 1)
            ans -= (n - i) * (m - j) * (std::__gcd(i, j) - 1) * 2;
    printf("%lld", ans);
    return 0;
}