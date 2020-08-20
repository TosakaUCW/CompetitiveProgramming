#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 5e4;

int v[N], prime[N], num_prime;
ll a, b, c, d;
ll m[5], cnt;
ll ans;

void Euler()
{
    for (int i = 2; i <= N; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (int j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or i * prime[j] > N)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

void go(int x)
{
    m[1] = m[2] = m[3] = m[4] = 0;
    while (d % x == 0)
        d /= x, m[4]++;
    while (c % x == 0)
        c /= x, m[3]++;
    while (b % x == 0)
        b /= x, m[2]++;
    while (a % x == 0)
        a /= x, m[1]++;
    if (m[1] == m[2] and m[3] == m[4])
        if (m[2] <= m[4])
            ans *= m[4] - m[2] + 1;
        else
            ans = 0;
    else if (m[1] != m[2] and m[3] != m[4] and m[2] != m[4])
        ans = 0;
}

int main()
{
    Euler();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 1, m[1] = m[2] = m[3] = m[4] = cnt = 0;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        for (int i = 1; i <= num_prime; i++)
            go(prime[i]);
        if (d != 1)
            go(d);
        printf("%lld\n", ans);
    }
    return 0;
}