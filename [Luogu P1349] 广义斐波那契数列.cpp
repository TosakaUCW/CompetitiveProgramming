#include <memory.h>
#include <stdio.h>

typedef long long ll;
#define Rep(i, x, y) for (int i = x; i <= y; i++)

const int MatrixSize = 2;

ll p, q, a1, a2, n, P;

struct Matrix
{
    ll a[MatrixSize + 5][MatrixSize + 5];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix friend operator*(Matrix A, Matrix B)
    {
        Matrix C;
        Rep(i, 1, MatrixSize)
            Rep(j, 1, MatrixSize)
                Rep(k, 1, MatrixSize)
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % P) % P;
        return C;
    }
} ans, base;

Matrix pow(Matrix x, ll k)
{
    while (k)
    {
        if (k & 1)
            ans = ans * x;
        x = x * x;
        k >>= 1;
    }
    return ans;
}

void Fibonacci(ll n)
{
    if (n == 1)
    {
        printf("%lld", a1);
        return;
    }
    if (n == 2)
    {
        printf("%lld", a2);
        return;
    }
    ans.a[1][1] = a2;
    ans.a[1][2] = a1;
    base.a[1][1] = p;
    base.a[1][2] = 1;
    base.a[2][1] = q;
    ans = pow(base, n - 2);
    printf("%lld", ans.a[1][1] % P);
}

int main()
{
    scanf("%lld%lld", &p, &q);
    scanf("%lld%lld", &a1, &a2);
    scanf("%lld%lld", &n, &P);
    Fibonacci(n);
    a1 %= P, a2 %= P;
    p %= P, q %= P;
    return 0;
}