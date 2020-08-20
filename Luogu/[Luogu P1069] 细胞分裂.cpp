#include <stdio.h>
#include <algorithm>
#include <math.h>

typedef long long ll;

const ll N = 5e5 + 5;
const ll INF = 2147483647;

ll n, m1, m2, s[N];
ll v[N], prime[N], num_prime;
ll res = INF;

void Euler()
{
    for (ll i = 2; i <= N; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (ll j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or prime[j] * i > N)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

int main()
{
    // freopen("x.in", "r", stdin);
    // freopen("x.ans", "w", stdout);
    Euler();
    scanf("%lld%lld%lld", &n, &m1, &m2);
    if (m1 == 1)
    {
        puts("0");
        return 0;
    }
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    // printf("%d %d %d\n", s[17], s[40], s[60]);
    for (ll i = 1; i <= n; i++)
    {
        bool flag = true;
        ll m = m1;
        ll ans = -1;
        for (ll j = 1; j <= num_prime and flag; j++)
        {
            ll a = 0, b = 0;
            while (m % prime[j] == 0 and m != 1)
                a += m2, m /= prime[j];
            while (s[i] % prime[j] == 0 and s[i] != 1)
                b++, s[i] /= prime[j];
            if (b == 0 and a != 0)
            {
                ans = -1, flag = false;
                break;
            }
            else if (a > b)
                ans = std::max(ans, (ll)ceil(1.0 * a / b));
            else if (b == a and a != 0)
                ans = std::max(ans, 1LL);
        }
        if (flag and ans != -1)
            res = std::min(res, ans);
    }
    printf("%lld", res == INF ? -1 : res);
    return 0;
}