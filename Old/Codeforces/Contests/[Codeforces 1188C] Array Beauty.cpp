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

#define int long long

const int N = 1e4 + 5;
const int P = 998244353;

int n, k, ans;
int a[N], f[N][N];

signed main()
{
    n = read(), k = read(), f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    for (int v = 1; v <= a[n] / (k - 1); (ans += f[n][k]) %= P, v++)
        for (int i = 1, pos = 0; i <= n; i++)
        {
            f[i][0] = 1;
            while (a[i] - a[pos + 1] >= v)
                pos++;
            for (int j = 1; j <= k; j++)
                f[i][j] = (f[i - 1][j] + f[pos][j - 1]) % P;
        }
    return printf("%lld", ans), 0;
}