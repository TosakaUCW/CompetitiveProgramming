#include <stdio.h>
#include <algorithm>
#include <math.h>

const int N = 1e5 + 5;

int n, ans;
int a[N], b[N];
int f[N], g[N];
int cnt, prime[N];
bool isPrime[N];

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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, tmp; i <= n; i++)
    {
        f[i] = 1, tmp = a[i];
        for (int j = 2; j * j <= a[i]; j++)
            if (tmp % j == 0)
            {
                f[i] = std::max(f[i], g[j] + 1);
                while (tmp % j == 0)
                    tmp /= j;
            }
        if (tmp > 1)
            f[i] = std::max(f[i], g[tmp] + 1);
        ans = std::max(ans, f[i]), tmp = a[i];
        for (int j = 2; j * j <= a[i]; j++)
            if (tmp % j == 0)
            {
                g[j] = std::max(g[j], f[i]);
                while (tmp % j == 0)
                    tmp /= j;
            }
        if (tmp > 1)
            g[tmp] = std::max(g[tmp], f[i]);
    }
    return printf("%d", ans), 0;
}