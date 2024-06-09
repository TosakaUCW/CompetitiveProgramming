#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <map>

typedef long long ll;

const ll N = 1e5 + 5;

ll n, m;
bool vis[N];
ll toi[N];
ll v[N], prime[N], num_prime;

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void Euler()
{
    for (ll i = 2; i <= 40000; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (ll j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or i * prime[j] > N)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

signed main()
{
    Euler();
    n = read(), m = read();
    while (m--)
    {
        char opt;
        ll x;
        std::cin >> opt >> x;
        if (opt == '+')
        {
            if (vis[x])
                puts("Already on");
            else
            {
                bool flag = true;
                for (ll i = 1; i <= num_prime and prime[i] <= x; i++)
                    if (x % prime[i] == 0 and toi[prime[i]] > 0)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    for (ll i = 1; i <= num_prime and prime[i] <= x; i++)
                        if (x % prime[i] == 0)
                            toi[prime[i]] = x;
                    vis[x] = true, puts("Success");
                }
                else
                {
                    for (ll i = 1; i <= num_prime and prime[i] <= x; i++)
                        if (x % prime[i] == 0 and toi[prime[i]] != 0)
                        {
                            printf("Conflict with %lld\n", toi[prime[i]]);
                            break;
                        }
                }
            }
        }
        else
        {
            if (!vis[x])
                puts("Already off");
            else
            {
                for (ll i = 1; i <= num_prime and prime[i] <= x; i++)
                    if (x % prime[i] == 0)
                        toi[prime[i]] = 0;
                vis[x] = false, puts("Success");
            }
        }
    }
    return 0;
}