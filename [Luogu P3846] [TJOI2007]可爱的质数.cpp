#include <math.h>
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

ll a, b, p;
__gnu_pbds::cc_hash_table<ll, ll> hash;

void BSGS(ll a, ll b, ll p)
{
    if (a == 0)
    {
        printf("no solution\n");
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
    printf("no solution\n");
}

int main()
{
    //a ^ x = b(mod p)
    scanf("%lld%lld%lld", &p, &a, &b);
    BSGS(a, b, p);
    return 0;
}