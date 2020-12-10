#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, m, P, min, max;
int c[N], sum[N];

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

signed main()
{
    n = read(), m = read(), P = read(), min = read(), max = read();
    for (char opt; m--;)
    {
        scanf("%s", &opt);
        int L = read(), R = read(), k, res = 0;
        if (opt == 'A')
            c[L] += k = read(), c[R + 1] -= k;
        else
        {
            for (int i = 1, x = 0, y = 0; i <= R; i++)
                x += c[i], y = x * i % P, res += min <= y and y <= max and i >= L;
            printf("%lld\n", res);
        }
    }
    for (int i = 1, x = 0, y = 0; i <= n; i++)
        x += c[i], y = x * i % P, sum[i] = sum[i - 1] + (min <= y and y <= max);
    for (m = read(); m--;)
    {
        int L = read(), R = read();
        printf("%lld\n", sum[R] - sum[L - 1]);
    }
    return 0;
}