#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;

int n, cnt;

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

struct Segment_tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int gcd[N << 2];
    void push_up(int p) { gcd[p] = std::__gcd(gcd[ls], gcd[rs]); }
    void build(int p, int l, int r)
    {
        if (l == r)
            return gcd[p] = read(), void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int k)
    {
        if (l == r)
            return gcd[p] = k, void();
        return x <= mid ? modify(ls, l, mid, x, k) : modify(rs, mid + 1, r, x, k), push_up(p), void();
    }
    void query(int p, int l, int r, int x, int y, int k)
    {
        if (cnt > 1)
            return;
        if (l == r)
            return ++cnt, void();
        if (x <= mid and gcd[ls] % k)
            query(ls, l, mid, x, y, k);
        if (mid < y and gcd[rs] % k)
            query(rs, mid + 1, r, x, y, k);
    }
} T;

int main()
{
    n = read(), T.build(1, 1, n);
    for (int q = read(), opt, x, y, k; q--; cnt = 0)
        if ((opt = read()) == 1)
            x = read(), y = read(), k = read(), T.query(1, 1, n, x, y, k), puts(cnt > 1 ? "NO" : "YES");
        else
            x = read(), k = read(), T.modify(1, 1, n, x, k);
    return 0;
}