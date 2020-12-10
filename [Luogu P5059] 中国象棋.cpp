// luogu-judger-enable-o2
#include <stdio.h>
#include <memory.h>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2;

ll n, P;

ll mul(ll a, ll b)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % P;
        a = (2 * a) % P;
        b >>= 1;
    }
    return res;
}

struct Matrix
{
    ll a[N + 5][N + 5];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    void build()
    {
        Rep(i, 1, N)
            a[i][i] = 1;
    }
    Matrix friend operator*(Matrix x, Matrix y)
    {
        Matrix z;
        Rep(k, 1, N)
            Rep(i, 1, N)
                Rep(j, 1, N)
                    z.a[i][j] = (z.a[i][j] + mul(x.a[i][k], y.a[k][j])) % P;
        return z;
    }
} ans, base;

ll pow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = mul(res, x) % P;
        x = mul(x, x) % P;
        k >>= 1;
    }
    return res;
}

ll Fibonacci(ll k)
{
    while (k)
    {
        if (k & 1)
            ans = ans * base;
        base = base * base;
        k >>= 1;
    }
    return ans.a[1][1];
}

int main()
{
    scanf("%lld%lld", &n, &P);
    ans.build();
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ll x = (Fibonacci(n + 2) - n - 2) % P + P;
    printf("%lld", pow(x, n + 1) % P);
    return 0;
}