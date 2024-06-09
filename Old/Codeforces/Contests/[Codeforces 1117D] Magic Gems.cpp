#include <memory.h>
#include <stdio.h>

typedef long long ll;

const int M = 100 + 5;
const int P = 1e9 + 7;

ll n, m;

struct Matrix
{
    ll size;
    ll a[M][M];
    Matrix() { size = 0, memset(a, 0, sizeof a); }
    Matrix friend operator*(Matrix A, Matrix B)
    {
        Matrix C;
        C.size = A.size;
        for (int i = 1; i <= A.size; i++)
            for (int k = 1; k <= A.size; k++)
                for (int j = 1; j <= B.size; j++)
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % P;
        return C;
    }
} A, B;

void build_matrix()
{
    A.size = B.size = m + 2;
    A.a[1][1] = A.a[1][m + 1] = A.a[1][m + 2] = 1;
    for (int i = 1; i <= m; i++)
        B.a[i][m + 1] = -1;
    B.a[m + 1][m + 1] = 2;
    B.a[m + 2][m + 1] = B.a[m + 2][m + 2] = 1;
    for (int i = 2; i <= m; i++)
        B.a[i - 1][i] = 1;
    for (int i = 1; i <= m; i++)
        B.a[i][1] = -1;
    B.a[m + 2][1] = B.a[m + 1][1] = 1;
    while (n)
    {
        if (n & 1)
            A = A * B;
        B = B * B;
        n >>= 1;
    }
}

int main()
{
    scanf("%I64d %I64d", &n, &m), m--;
    build_matrix();
    printf("%I64d", A.a[1][1]);
    return 0;
}