#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e2 + 5;
const int K = 2e4 + 5;
const int P = 504;

int n, k, ans;
int f[N][K], g[N];

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
    freopen("empire.in", "r", stdin), freopen("empire.out", "w", stdout);
    n = read(), k = read(), g[2 * n - 1] = 2 * n - 1;
    if (k >= 2 * n)
        return puts("0"), 0;
    for (int i = 1; i < n; i++)
        g[2 * i] = g[2 * i - 1] = 2 * i - 1;
    for (int i = 0; i < 2 * n; i++)
        f[i][0] = 1;
    for (int i = 1; i < 2 * n; i++)
        for (int k = 1; k <= g[i]; k++)
            f[i][k] = (f[i - 1][k] + f[i - 1][k - 1] * (g[i] - k + 1) % P) % P;
    return printf("%d", f[2 * n - 1][k]), 0;
}