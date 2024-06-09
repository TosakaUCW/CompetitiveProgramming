#include <stdio.h>
#include <memory.h>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

const int N = 100;
const ll P = 1e9 + 7;

ll n, k;

struct Matrix
{
    ll a[N + 5][N + 5];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    void build()
    {
        Rep(i, 1, n)
            a[i][i] = 1;
    }
    Matrix friend operator*(Matrix x, Matrix y)
    {
        Matrix z;
        Rep(k, 1, n)
            Rep(i, 1, n)
                Rep(j, 1, n)
                    z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j] % P) % P;
        return z;
    }
} a, ans;

Matrix pow(Matrix x, ll k)
{
    Matrix res;
    res.build();
    while (k)
    {
        if (k & 1)
            res = res * x;
        x = x * x;
        k >>= 1;
    }
    return res;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    Rep(i, 1, n)
        Rep(j, 1, n)
            scanf("%lld", &a.a[i][j]);
    ans = pow(a, k);
    Rep(i, 1, n)
    {
        Rep(j, 1, n)
            printf("%lld ", ans.a[i][j]);
        printf("\n");
    }
    return 0;
}