#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

typedef long long ll;

const ll N = 1e6 + 5;
const ll INF = 2147483647;

ll L, R, ans_min = INF, ans_max;
ll prime[N], v[N], num_prime;
ll vec[N], cnt;
bool vis[N];

void Euler(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (ll j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or prime[j] * i > n)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

int main()
{
    while (scanf("%lld%lld", &L, &R) != EOF)
    {
        memset(vis, 0, sizeof vis);
        cnt = 0, num_prime = 0;
        ans_min = INF, ans_max = 0;
        memset(v, 0, sizeof v);
        if (L == 1)
            vis[0] = true;
        Euler(sqrt(R));
        // for (ll i = 1; i <= num_prime; i++)
        // printf("%d\n", prime[i]);
        for (ll i = 1; i <= num_prime; i++)
            for (ll j = L / prime[i]; j <= R / prime[i]; j++)
            {
                if (prime[i] * j - L < 0)
                    continue;
                if (j > 1)
                    vis[prime[i] * j - L] = true;
            }
        for (ll i = L; i <= R; i++)
            if (!vis[i - L])
                vec[++cnt] = i;
        ll x1, y1, x2, y2;
        for (ll i = 1; i < cnt; i++)
        {
            ll k = vec[i + 1] - vec[i];
            if (k < ans_min)
                ans_min = k, x2 = vec[i], y2 = vec[i + 1];
            if (k > ans_max)
                ans_max = k, x1 = vec[i], y1 = vec[i + 1];
        }
        if (ans_max)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", x2, y2, x1, y1);
        else
            puts("There are no adjacent primes.");
    }
    return 0;
}