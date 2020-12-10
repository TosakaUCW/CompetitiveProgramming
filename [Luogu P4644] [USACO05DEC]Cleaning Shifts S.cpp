#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 86400 + 5;
const int M = 86400 + 5;
const int INF = 0x3f3f3f3f;

int n, L, R, f[M];

struct Node
{
    int L, R, w;
    bool friend operator<(Node a, Node b) { return a.R < b.R; }
} a[N];

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
    int min[N << 2];
    void push_up(int p) { min[p] = std::min(min[ls], min[rs]); }
    void modify(int p, int l, int r, int pos, int val)
    {
        if (l == r)
            return min[p] = val, void();
        if (pos <= mid)
            modify(ls, l, mid, pos, val);
        else
            modify(rs, mid + 1, r, pos, val);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return min[p];
        int res = INF;
        if (x <= mid)
            res = std::min(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::min(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read(), L = read() + 1, R = read() + 1;
    for (int i = 1; i <= n; i++)
        a[i].L = std::max(read() + 1, L), a[i].R = std::min(read() + 1, R), a[i].w = read();
    memset(f, 0x3f, sizeof f), memset(T.min, 0x3f, sizeof T.min);
    f[L - 1] = 0, T.modify(1, L - 1, R, L - 1, 0), std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        f[a[i].R] = std::min(f[a[i].R], T.query(1, L - 1, R, a[i].L - 1, a[i].R) + a[i].w),
        T.modify(1, L - 1, R, a[i].R, f[a[i].R]);
    return printf("%d", f[R] == INF ? -1 : f[R]), 0;
}