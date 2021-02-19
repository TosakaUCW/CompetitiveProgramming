#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e2 + 5;
const int M = 1e5 + 5;

int n, sum, ans;
int a[N], f[N][M];

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        sum += (a[i] = read());
    memset(f, 0xcf, sizeof f), f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            f[i][j] = std::max(f[i - 1][j], f[i - 1][j + a[i]] + a[i]),
            f[i][j] = std::max(f[i][j], f[i - 1][abs(j - a[i])] + a[i]);
    return printf("%d", sum - f[n][0] / 2), 0;
}
