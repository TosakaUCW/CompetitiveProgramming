#include <stdio.h>
#include <algorithm>

#define int long long

const int N = 2e2 + 5;
const int magic = 4999987;
const int P = 9999973;

int n, m, ans;
int fac[N], inv[N];
int f[N][N][N];

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

int C(int n) { return n * (n - 1) % P * magic % P; }

signed main()
{
    n = read(), m = read(), f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k + j <= m; f[i][j][k++] %= P)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (k >= 1)
                    f[i][j][k] += f[i - 1][j + 1][k - 1] * (j + 1) % P,
                        f[i][j][k] += f[i - 1][j][k - 1] * j * (m - j - k + 1) % P;
                if (k >= 2)
                    f[i][j][k] += f[i - 1][j + 2][k - 2] * C(j + 2) % P;
                if (j >= 1)
                    f[i][j][k] += f[i - 1][j - 1][k] * (m - j - k + 1) % P;
                if (j >= 2)
                    f[i][j][k] += f[i - 1][j - 2][k] * C(m - j - k + 2) % P;
            }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            (ans += f[n][i][j]) %= P;
    return printf("%lld", (ans + P) % P), 0;
}