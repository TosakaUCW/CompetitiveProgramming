#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 50 + 5;

int n, c;
int a[N], b[N], sum[N];
int f[N][N][2];

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
    n = read(), c = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(), sum[i] = sum[i - 1] + b[i];
    memset(f, 127, sizeof f);
    f[c][c][0] = f[c][c][1] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1, j = i + len - 1; j <= n; i++, j++)
        {
            f[i][j][0] = std::min(f[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j]),
                                  f[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j]));
            f[i][j][1] = std::min(f[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]),
                                  f[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    printf("%d", std::min(f[1][n][0], f[1][n][1]));
    return 0;
}