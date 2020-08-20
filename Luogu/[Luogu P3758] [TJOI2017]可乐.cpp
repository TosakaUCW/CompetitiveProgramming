#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int K = 30;
const int P = 2017;

int n, m, k, ans;

struct Matrix
{
    int a[K + 5][K + 5];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix friend operator*(Matrix A, Matrix B)
    {
        Matrix C;
        for (int i = 0; i <= K; i++)
            for (int k = 0; k <= K; k++)
                for (int j = 0; j <= K; j++)
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % P) % P;
        return C;
    }
} M, ansM;

Matrix pow(Matrix A, int k)
{
    Matrix C;
    for (int i = 0; i <= K; i++)
        C.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            C = C * A;
        A = A * A;
        k >>= 1;
    }
    return C;
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), M.a[u][v] = M.a[v][u] = 1;
    for (int i = 0; i <= n; i++)
        M.a[i][i] = 1;
    for (int i = 1; i <= n; i++)
        M.a[i][0] = 1;
    k = read();
    ansM = pow(M, k);
    for (int i = 0; i <= n; i++)
        ans = (ans + ansM.a[1][i]) % P;
    printf("%d", ans);
    return 0;
}