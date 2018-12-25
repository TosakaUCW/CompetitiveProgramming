#include <math.h>
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

ll a, b, p;
__gnu_pbds::cc_hash_table<ll, ll> hash;

ll pow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

void BSGS(ll a, ll b, ll p)
{
    if (a == 0)
    {
        printf("Orz, I cannot find x!\n");
        return;
    }
    hash.clear();
    int m = ceil(sqrt(p));
    ll base = 1, tmp = 0;
    Rep(i, 0, m)
    {
        hash[base * b % p] = i;
        tmp = base;
        base = base * a % p;
    }
    base = tmp;
    Rep(i, 1, m)
    {
        if (hash[base])
        {
            printf("%lld\n", i * m - hash[base]);
            return;
        }
        base = base * tmp % p;
    }
    printf("Orz, I cannot find x!\n");
}

int main()
{
    int T, opt;
    scanf("%d%d", &T, &opt);
    while (T--)
    {
        scanf("%lld%lld%lld", &a, &b, &p);
        a %= p;
        switch (opt)
        {
        case 1:
            printf("%lld\n", pow(a, b));
            break;
        case 2:
            b %= p;
            if (a == 0 and b != 0)
                printf("Orz, I cannot find x!\n");
            else
                printf("%lld\n", ((b % p) * pow(a, p - 2)) % p);
            break;
        case 3:
            BSGS(a, b, p);
            break;
        }
    }
    return 0;
}