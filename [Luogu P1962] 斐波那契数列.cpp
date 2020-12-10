#include <stdio.h>
#include <memory.h>

typedef long long ll;
#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2;
const int P = 1e9 + 7;

ll n;

struct Matrix
{
    ll a[N + 5][N + 5];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    Matrix friend operator*(Matrix x, Matrix y)
    {
        Matrix z;
        Rep(i, 1, N)
            Rep(j, 1, N)
                Rep(k, 1, N)
                    z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j] % P) % P;
        return z;
    }
} ans, base;

Matrix pow(Matrix base, ll k)
{
    while (k)
    {
        if (k & 1)
            ans = ans * base;
        base = base * base;
        k >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%lld", &n);
    if (n <= 2)
    {
        printf("1");
        return 0;
    }
    ans.a[1][1] = ans.a[1][2] = 1;
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ans = pow(base, n - 2);
    printf("%lld\n", ans.a[1][1] % P);
    return 0;
}