#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, m, p;

struct Node
{
    int a, b, c;
    bool friend operator<(Node a, Node b) { return a.c > b.c; }
} a[N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

bool judge(int x)
{
    x = x * 85LL + p * 15LL;
    int res = n + 1;
    for (int L = 1, R = n, mid; L <= R;)
    {
        mid = (L + R) / 2LL;
        if (x >= a[mid].c)
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    }

    // printf("%lld %lld\n", x, res);
    return res <= m;
}

signed main()
{
    n = read(), m = read(), p = read();
    for (int i = 1; i <= n; i++)
        a[i].a = read(), a[i].b = read(), a[i].c = a[i].a * 85LL + a[i].b * 15LL;
    std::sort(a + 1, a + 1 + n);
    int res = -1;
    for (int L = 0, R = 1e9, mid; L <= R;)
    {
        mid = (L + R) / 2LL;
        if (judge(mid))
            res = mid,
            R = mid - 1;
        else
            L = mid + 1;
    }
    // for (int i = 1; i <= n; i++)
    // printf("%lld|", a[i].c);
    return printf("%lld", res), 0;
}
/*
A + B = C
  + 100 = C
*/