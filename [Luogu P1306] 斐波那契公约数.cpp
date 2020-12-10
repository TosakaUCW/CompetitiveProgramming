#include <memory.h>
#include <stdio.h>

typedef long long ll;

const int N = 2;
const int P = 1e8;

ll n, m;

struct Matrix
{
    ll a[N + 5][N + 5];
    Matrix() { memset(a, 0, sizeof(a)); }
    Matrix friend operator*(Matrix X, Matrix Y)
    {
        Matrix Z;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= N; k++)
                    Z.a[i][j] = (Z.a[i][j] + X.a[i][k] * Y.a[k][j] % P) % P;
        return Z;
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

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    n = gcd(n, m);
    if (n <= 2)
    {
        printf("1");
        return 0;
    }
    ans.a[1][1] = ans.a[1][2] = 1;
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    ans = pow(base, n - 2);
    printf("%lld", ans.a[1][1]);
    return 0;
}