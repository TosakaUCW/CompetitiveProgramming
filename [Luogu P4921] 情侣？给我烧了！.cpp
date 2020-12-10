#include <stdio.h>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e6;
const int P = 998244353;

ll n, ans;
ll f[N + 5], fac[N + 5], inv[N + 5];

ll pow(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y % 2)
            ans = ans * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return ans;
}

void prepare()
{
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    Rep(i, 2, N)
        fac[i] = fac[i - 1] * i % P;
    Rep(i, 2, N)
        inv[i] = (P - P / i) * inv[P % i] % P;
    Rep(i, 2, N)
        inv[i] = inv[i - 1] * inv[i] % P;
    f[0] = 1;
    Rep(i, 2, N)
    {
        f[i] = ((2 * i - 2) % P * f[i - 2] % P + f[i - 1]) % P;
        f[i] = (f[i] * 4 % P * i % P * (i - 1) % P) % P;
    }
}

void answer(ll n, ll k)
{
    ans = 0;
    ans = fac[n] * inv[n - k] % P; //代表A(n,k)
    ans = ans * fac[n] % P * inv[n - k] % P * inv[k] % P;
    ans = ans * pow(2, k) % P * f[n - k] % P;
    printf("%lld\n", ans);
}

int main()
{
    prepare();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        Rep(i, 0, n)
            answer(n, i);
    }
    return 0;
}