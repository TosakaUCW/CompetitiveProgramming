#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 8e2 + 5;
const int T = 15 + 5;
const int P = 1e9 + 7;

int n, m, t, ans;
int a[N][N], f[N][N][T][2];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    n = read(), m = read(), t = read() + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), f[i][j][a[i][j]][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < t; k++)
            {
                (f[i][j][k][0] += f[i - 1][j][(k - a[i][j] + t) % t][1]) %= P;
                (f[i][j][k][0] += f[i][j - 1][(k - a[i][j] + t) % t][1]) %= P;
                (f[i][j][k][1] += f[i - 1][j][(k + a[i][j] + t) % t][0]) %= P;
                (f[i][j][k][1] += f[i][j - 1][(k + a[i][j] + t) % t][0]) %= P;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            (ans += f[i][j][0][1]) %= P;
    return printf("%d", (ans + P) % P), 0;
}