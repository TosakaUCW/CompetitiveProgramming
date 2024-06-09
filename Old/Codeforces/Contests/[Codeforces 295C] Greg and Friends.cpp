#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e2 + 5;
const int K = 5e3 + 5;
const int P = 1e9 + 7;

int n, m, X, Y;
int f[4 * N][N][N], fac[K];

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

int pow(int x, int k)
{
    int res = 1;
    for (x %= P; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return (res + P) % P;
}

int C(int n, int m) { return m > n ? 0 : fac[n] * pow(fac[m], P - 2) % P * pow(fac[n - m], P - 2) % P; }

signed main()
{
    n = read(), m = read();
    for (int i = 1, x; i <= n; i++)
        x = read(), x == 50 ? X++ : Y++;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % P;
    f[0][X][Y] = 1;
    for (int i = 1; i <= 4 * n + 1; i += 2)
    {
        for (int x = 0; x <= X; x++)
            for (int y = 0; y <= Y; y++)
                if (f[i - 1][x][y])
                    for (int a = 0; a <= x; a++)
                        for (int b = 0; b <= y; b++)
                            if ((a | b) and a * 50LL + b * 100LL <= m)
                                (f[i][x - a][y - b] += C(x, a) * C(y, b) * f[i - 1][x][y]) %= P;
        if (f[i][0][0])
            return printf("%I64d\n%I64d", i, f[i][0][0]), 0;
        for (int x = 0; x <= X; x++)
            for (int y = 0; y <= Y; y++)
                if (f[i][x][y])
                    for (int a = 0; a <= X - x; a++)
                        for (int b = 0; b <= Y - y; b++)
                            if ((a | b) and a * 50LL + b * 100LL <= m)
                                (f[i + 1][x + a][y + b] += C(X - x, a) * C(Y - y, b) * f[i][x][y]) %= P;
    }
    return puts("-1\n0"), 0;
}