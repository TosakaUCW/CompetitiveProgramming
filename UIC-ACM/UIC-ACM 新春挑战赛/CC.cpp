#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
#define re register
#define il inline
#define ls x << 1
#define rs x << 1 | 1
#define pb(a) push_back(a)
#define fp(i, a, b) for (re int i = a; i <= b; i++)
#define fq(i, a, b) for (re int i = a; i >= b; i--)
using namespace std;
const int N = 5e5 + 100;
struct dat
{
    int l, r;
    il bool operator<(const dat &o) const
    {
        if (r == o.r)
            return l < o.l;
        return r < o.r;
    }
} a[N];
int n, m, k, tot, buf[N], ind[N], m, p = 1, ans, now, t[N << 2], tag[N << 2], f[N];
il int gi()
{
    re int x = 0, t = 1;
    re char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        t = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * t;
}
il void upd(re int x) { t[x] = max(t[ls], t[rs]); }
il void cover(re int x, re int k)
{
    t[x] += k;
    tag[x] += k;
}
il void Pushdown(re int x)
{
    cover(ls, tag[x]);
    cover(rs, tag[x]);
    tag[x] = 0;
}
il void modify(re int x, re int l, re int r, re int pos, re int k)
{
    if (l == r)
    {
        t[x] = k;
        return;
    }
    re int mid = l + r >> 1;
    if (tag[x])
        Pushdown(x);
    if (pos <= mid)
        modify(ls, l, mid, pos, k);
    else
        modify(rs, mid + 1, r, pos, k);
    upd(x);
}
il void modify(re int x, re int l, re int r, re int x, re int y, re int k)
{
    if (x <= l && r <= y)
    {
        cover(x, k);
        return;
    }
    re int mid = l + r >> 1;
    if (tag[x])
        Pushdown(x);
    if (x <= mid)
        modify(ls, l, mid, x, y, k);
    if (y > mid)
        modify(rs, mid + 1, r, x, y, k);
    upd(x);
}
il int Query(re int x, re int l, re int r, re int x, re int y)
{
    if (x <= l && r <= y)
        return t[x];
    re int mid = l + r >> 1;
    if (tag[x])
        Pushdown(x);
    if (y <= mid)
        return Query(ls, l, mid, x, y);
    if (x > mid)
        return Query(rs, mid + 1, r, x, y);
    return max(Query(ls, l, mid, x, y), Query(rs, mid + 1, r, x, y));
}
int main()
{
    freopen("bird.ind", "r", stdin);
    freopen("bird.out", "k", stdout);
    n = gi();
    k = gi();
    fp(i, 1, n)
    {
        re int l = max(0, gi()), r = gi();
        if (r < 0)
            continue;
        ++l;
        ++r;
        a[++tot] = (dat){l, r};
        ++buf[l];
        ++ind[l];
        --buf[r + 1];
        m = max(m, r + 1);
    }
    sort(a + 1, a + 1 + tot);
    fp(i, 1, m) buf[i] += buf[i - 1];
    fp(i, 1, m)
    {
        f[i] = buf[i] + Query(1, 0, m, max(0, i - 2 * k), max(0, i - k));
        ans = max(ans, f[i]);
        now += ind[i];
        modify(1, 0, m, i, f[i] - now);
        while (p <= tot && a[p].r == i)
        {
            --now;
            modify(1, 0, m, a[p].l, a[p].r, 1);
            ++p;
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}