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

const int N = 1e5 + 5;

int n, m;

struct Node
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int sum[N << 2], max[N << 2];
    void push_up(int p)
    {
        sum[p] = sum[ls] + sum[rs],
        max[p] = std::max(max[ls], max[rs]);
    }
    void build(int p, int l, int r)
    {
        if (l == r)
            return sum[p] = max[p] = read(), void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int pos, int val)
    {
        if (l == r and l == pos)
            return max[p] = sum[p] = val, void();
        if (pos <= mid)
            modify(ls, l, mid, pos, val);
        else
            modify(rs, mid + 1, r, pos, val);
        push_up(p);
    }
    void modify_mod(int p, int l, int r, int x, int y, int val)
    {
        if (l == r)
            return max[p] %= val, sum[p] %= val, void();
        if (x <= mid and max[ls] >= val)
            modify_mod(ls, l, mid, x, std::min(y, mid), val);
        if (mid < y and max[rs] >= val)
            modify_mod(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return sum[p];
        int res = 0;
        if (x <= mid)
            res += query(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), m = read(), T.build(1, 1, n);
    for (int opt, l, r; m--;)
    {
        opt = read(), l = read(), r = read();
        if (opt == 1)
            printf("%lld\n", T.query(1, 1, n, l, r));
        if (opt == 2)
            T.modify_mod(1, 1, n, l, r, read());
        if (opt == 3)
            T.modify(1, 1, n, l, r);
    }
    return 0;
}