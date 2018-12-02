#include <stdio.h>
#include <memory.h>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

const ll N = 3;
const ll P = 1e9 + 7;

int T, n;

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
    void clear()
    {
        memset(a, 0, sizeof(a));
    }
    Matrix friend operator*(Matrix x, Matrix y)
    {
        Matrix z;
        Rep(k, 1, N)
            Rep(i, 1, N)
                Rep(j, 1, N)
                    z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j] % P) % P;
        return z;
    }
} ans, base;

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
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n <= 3)
        {
            printf("1\n");
            continue;
        }
        base.clear();
        ans.clear();
        ans.build();
        base.a[1][1] = base.a[1][3] = base.a[2][1] = base.a[3][2] = 1;
        ans = pow(base, n);
        printf("%lld\n", ans.a[2][1]);
    }
    return 0;
}