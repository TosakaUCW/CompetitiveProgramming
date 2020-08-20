#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;

int n, m, C, v, w, d;
int f[N];

inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main()
{
    n = read(), m = read(), C = read();
    for (int i = 1; i <= n; i++)
    {
        v = read(), w = read(), d = read();
        if (d * v > C)
            for (int j = v; j <= C; j++)
                f[j] = std::max(f[j], f[j - v] + w);
        else
            for (int k = 1; k <= d; d -= k, k *= 2)
                for (int j = C; j >= v * k; j--)
                    f[j] = std::max(f[j], f[j - v * k] + w * k);
        if (d > 0)
            for (int j = C; j >= v * d; j--)
                f[j] = std::max(f[j], f[j - v * d] + w * d);
    }
    for (int i = 1; i <= m; i++)
    {
        v = read(), w = read(), d = read();
        for (int j = C; j; j--)
            for (int k = 0; k <= j; k++)
                f[j] = std::max(f[j], f[j - k] + (v * k + w) * k + d);
    }
    printf("%d", f[C]);
    return 0;
}