#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, m, a[N], c[N];

struct fenwick
{
    int c[N];
    void modify(int x, int val = 1)
    {
        if (x)
            for (; x <= n; x += x & -x)
                c[x] += val;
    }
    int query(int x, int res = 0)
    {
        for (; x; x -= x & -x)
            res += c[x];
        return res;
    }
} u, v;

void modify(int x, int val = 1) { u.modify(x, val), v.modify(x, x * val); }

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = i - u.query(a[i]) - 1, u.modify(a[i]);
    memset(u.c, 0, sizeof u.c);
    for (int i = 1; i <= n; i++)
        modify(c[i]);
    for (int opt, x; m--;)
    {
        opt = read(), x = read();
        if (opt == 1)
        {
            modify(c[x], -1), modify(c[x + 1], -1);
            if (a[x] > a[x + 1])
                --c[x + 1];
            else
                ++c[x];
            std::swap(a[x], a[x + 1]), std::swap(c[x], c[x + 1]);
            modify(c[x], 1), modify(c[x + 1], 1);
        }
        else
            printf("%lld\n", x >= n ? 0 : v.query(n) - v.query(x) - x * (u.query(n) - u.query(x)));
    }
    return 0;
}