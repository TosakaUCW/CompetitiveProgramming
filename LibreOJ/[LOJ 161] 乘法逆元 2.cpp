#include <stdio.h>

typedef long long ll;

const int N = 5e6 + 5;
const ll P = 1e9 + 7;

ll n, ans;
ll a[N], pre[N], inv[N];

inline ll read()
{
    int p = 1, x = 0;
    char ch = getchar();
    while (ch < '0' or ch > '9')
    {
        if (ch == '-')
            p = -1;
        ch = getchar();
    }
    while (ch >= '0' and ch <= '9')
    {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return p * x;
}

ll pow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

int main()
{
    n = read();
    pre[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read(), pre[i] = pre[i - 1] * a[i] % P;
    inv[n] = pow(pre[n], P - 2);
    for (int i = n - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * a[i + 1] % P;
    for (int i = 1; i <= n; i++)
        ans = (ans * 998244353 + pre[i - 1] * inv[i] % P) % P;
    printf("%lld", ans);
    return 0;
}