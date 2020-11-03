#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

#define int long long

const int N = 3e5 + 5;

int n, a, ans;
int d[N], c[N], st[N][21], pos[N][21], lg[N];

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
    struct Node
    {
        int l, r, lmax, rmax, sum;
        Node() { l = r = lmax = rmax = sum = 0; }
        Node friend operator+(Node LS, Node RS)
        {
            Node p;
            p.l = p.r = p.lmax = p.rmax = p.sum = 0;
            p.l = LS.l, p.r = RS.r;
            p.lmax = std::max(LS.lmax, LS.sum + RS.lmax);
            p.rmax = std::max(RS.rmax, RS.sum + LS.rmax);
            p.sum = LS.sum + RS.sum;
            return p;
        }
    } t[N << 2];
    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r;
        if (l == r)
        {
            t[p].lmax = t[p].rmax = std::max(c[l], 0LL);
            t[p].sum = c[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid), build(rs, mid + 1, r), t[p] = t[ls] + t[rs];
    }
    Node query(int p, int x, int y)
    {
        if (x > y)
            return Node();
        if (x <= t[p].l and t[p].r <= y)
            return t[p];
        int mid = (t[p].l + t[p].r) >> 1;
        if (x <= mid and mid < y)
            return query(ls, x, y) + query(rs, x, y);
        if (x <= mid)
            return query(ls, x, y);
        if (mid < y)
            return query(rs, x, y);
    }
} T;

std::pair<int, int> query(int l, int r)
{
    int k = lg[r - l + 1], x = st[l][k], y = st[r - (1 << k) + 1][k];
    return x > y ? std::make_pair(x, pos[l][k]) : std::make_pair(y, pos[r - (1 << k) + 1][k]);
}

void solve(int l, int r)
{
    if (l == r)
        return;
    std::pair<int, int> t = query(l, r - 1);
    int pos = t.second, now = c[pos + 1] + c[pos] - t.first;
    now += T.query(1, l, pos - 1).rmax + T.query(1, pos + 2, r).lmax;
    ans = std::max(ans, now), solve(l, pos), solve(pos + 1, r);
}

signed main()
{
    n = read(), a = read(), lg[0] = -1;
    for (int i = 1; i <= n; i++)
        d[i] = read(), c[i] = a - read(), ans = std::max(ans, c[i]);
    T.build(1, 1, n);
    for (int i = 1; i < n; i++)
        st[i][0] = (d[i + 1] - d[i]) * (d[i + 1] - d[i]),
        pos[i][0] = i,
        lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= 18; j++)
        for (int i = 1; i <= n - (1 << (j - 1)) + 1; i++)
        {
            int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
            if (x > y)
                st[i][j] = x, pos[i][j] = pos[i][j - 1];
            else
                st[i][j] = y, pos[i][j] = pos[i + (1 << (j - 1))][j - 1];
        }
    return solve(1, n), printf("%lld", ans), 0;
}