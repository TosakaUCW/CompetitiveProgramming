#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, q;
int v[N], c[N], f[N];

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
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        v[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (; q--;)
    {
        memset(f, 0xcf, sizeof f);
        int a = read(), b = read(), fir_col = 0, sec_col = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int res = std::max(b * v[i], f[c[i]] + a * v[i]);
            if (c[i] != fir_col)
                res = std::max(res, f[fir_col] + b * v[i]);
            else
                res = std::max(res, f[sec_col] + b * v[i]);
            if (res > f[fir_col] and c[i] != fir_col)
                sec_col = fir_col, fir_col = c[i];
            else if (res > f[sec_col] and c[i] != fir_col)
                sec_col = c[i];
            f[c[i]] = std::max(f[c[i]], res);
            ans = std::max(ans, res);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}