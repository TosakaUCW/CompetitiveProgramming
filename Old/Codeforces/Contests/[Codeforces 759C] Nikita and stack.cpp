#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int m, a[N];

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

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int lazy[N << 2], max[N << 2];
    void push_down(int p)
    {
        if (lazy[p])
        {
            max[ls] += lazy[p], max[rs] += lazy[p];
            lazy[ls] += lazy[p], lazy[rs] += lazy[p];
            lazy[p] = 0;
        }
    }
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (l == x and r == y)
            return lazy[p] += val, max[p] += val, void();
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), val);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
    int query(int p, int l, int r)
    {
        if (max[1] <= 0)
            return -1;
        if (l == r)
            return a[l];
        push_down(p);
        if (max[rs] > 0)
            return query(rs, mid + 1, r);
        else
            return query(ls, l, mid);
    }
} T;

int main()
{
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int t = read(), opt = read();
        if (opt)
            a[t] = read(), T.modify(1, 1, m, 1, t, 1);
        else
            T.modify(1, 1, m, 1, t, -1);
        printf("%d\n", T.query(1, 1, m));
    }
    return 0;
}