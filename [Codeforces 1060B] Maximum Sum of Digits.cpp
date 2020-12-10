#include <stdio.h>

typedef long long ll;

ll n;

ll S(ll num)
{
    ll res = 0;
    while (num)
        res += num % 10, num /= 10;
    return res;
}

ll last(ll num)
{
    while (num >= 10)
        num /= 10;
    return num;
}

int main()
{
    scanf("%lld", &n);
    ll tmp = n;
    ll x = last(n) - 1;
    while (tmp)
        x = x * 10 + 9,
        tmp /= 10;
    x /= 10;
    printf("%lld", S(x) + S(n - x));
    return 0;
}