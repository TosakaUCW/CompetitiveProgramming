#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 2e5 + 5;
const ll P = 998244353;

ll n, ans;
ll a[N];
ll bull[N], sum[N];
bool vis[N];
ll fac[N];

void GetFac()
{
    fac[0] = 1;
    for (ll i = 1; i <= N - 5; i++)
        fac[i] = fac[i - 1] * i % P;
}

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

ll C(ll n, ll m)
{
    if (m > n)
        return 0;
    return ((fac[n] * pow(fac[m], P - 2)) % P * pow(fac[n - m], P - 2) % P);
}

ll Lucas(ll n, ll m)
{
    if (!m)
        return 1;
    return C(n % P, m % P) * Lucas(n / P, m / P) % P;
}

int main()
{
    GetFac();
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]), bull[a[i]]++;
    std::sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (ll i = 1; i <= n; i++)
        if (bull[a[i]] < 2 or vis[a[i]])
            continue;
        else
        {
            ll L = 1, R = n, res;
            vis[a[i]] = true;
            while (L <= R)
            {
                ll mid = (L + R) / 2;
                if (a[mid] < a[i] * 2)
                    res = mid, L = mid + 1;
                else
                    R = mid - 1;
            }
            // printf("%d %d\n", a[i], res - bull[a[i]]);
            ll k = res - bull[a[i]];
            (ans += Lucas(bull[a[i]], 3)) %= P;
            if (k != 0)
                (ans += Lucas(bull[a[i]], 2) * k) %= P;
        }
    printf("%lld", ans);
    return 0;
}