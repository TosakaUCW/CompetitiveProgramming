#include <stdio.h>

typedef long long ll;

const ll P = 123456789;

ll k;

ll pow(ll base, ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * base % P;
        base = base * base % P;
        k >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%lld", &k);
    printf("%lld", pow(2, k - 1));
    return 0;
}