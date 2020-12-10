#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 2e5 + 5;

int n, m;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int sum[N << 2], min[N << 2], max[N << 2], tag[N << 2];
    void push_up(int p)
    {
        sum[p] = sum[ls] + sum[rs];
        max[p] = std::max(max[ls], max[rs]);
        min[p] = std::min(min[ls], min[rs]);
    }
    void push_down(int p, int l, int r)
    {
        if (tag[p])
        {
            tag[ls] = tag[rs] = tag[p];
            min[ls] = max[ls] = min[rs] = max[rs] = tag[p];
            sum[ls] = tag[p] * (mid - l + 1);
            sum[rs] = tag[p] * (r - mid);
            tag[p] = 0;
        }
    }
    void build(int p, int l, int r)
    {
        if (l == r)
            return sum[p] = max[p] = min[p] = read(), void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (l == x and r == y and max[p] <= val)
            return tag[p] = max[p] = min[p] = val, sum[p] = val * (r - l + 1), void();
        push_down(p, l, r);
        if (x <= mid and min[ls] < val)
            modify(ls, l, mid, x, std::min(y, mid), val);
        if (mid < y and min[rs] < val)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y, int &val)
    {
        if (l == x and r == y and sum[p] <= val)
            return val -= sum[p], r - l + 1;
        push_down(p, l, r);
        int res = 0;
        if (x <= mid and min[ls] <= val)
            res += query(ls, l, mid, x, std::min(y, mid), val);
        if (mid < y and min[rs] <= val)
            res += query(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        return res;
    }
} T;

signed main()
{
    memset(T.min, 0x3f, sizeof T.min);
    n = read(), m = read(), T.build(1, 1, n);
    for (int opt, x, y; m--;)
    {
        opt = read(), x = read(), y = read();
        if (opt == 1)
            T.modify(1, 1, n, 1, x, y);
        else
            printf("%lld\n", T.query(1, 1, n, x, n, y));
    }
    return 0;
}