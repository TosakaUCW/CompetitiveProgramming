#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];

struct Query
{
    int x, y, k;
} q[N];

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int col[N << 2], lazy[N << 2];
    void push_down(int p)
    {
        if (lazy[p])
            col[ls] = col[rs] = lazy[ls] = lazy[rs] = lazy[p], lazy[p] = 0;
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
        {
            col[p] = lazy[p] = k;
            return;
        }
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
    }
    int query(int p, int l, int r, int x)
    {
        if (l == r)
            return col[p];
        push_down(p);
        if (x <= mid)
            return query(ls, l, mid, x);
        else
            return query(rs, mid + 1, r, x);
    }
} T;

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

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int opt = read();
        if (opt == 1)
        {
            q[i].x = read(), q[i].y = read(), q[i].k = read();
            T.modify(1, 1, n, q[i].y, q[i].y + q[i].k - 1, i);
        }
        else
        {
            int x = read(), k = T.query(1, 1, n, x);
            printf("%d\n", !k ? b[x] : a[q[k].x + x - q[k].y]);
        }
    }
    return 0;
}