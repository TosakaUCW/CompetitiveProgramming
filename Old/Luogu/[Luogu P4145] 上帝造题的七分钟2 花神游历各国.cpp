#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 1e5 + 5;

int n, m;
ll a[N];

namespace Segment_Tree
{
struct Node
{
    int l, r;
    ll sum, maxn;
} t[4 * N];

void push_up(int p)
{
    t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;
    t[p].maxn = std::max(t[2 * p].maxn, t[2 * p + 1].maxn);
}

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].sum = t[p].maxn = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid), build(2 * p + 1, mid + 1, r);
    push_up(p);
}

void modify(int p, int l, int r)
{
    if (t[p].maxn <= 1)
        return;
    if (t[p].l == t[p].r)
    {
        t[p].sum = t[p].maxn = sqrt(t[p].sum);
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if (l <= mid)
        modify(2 * p, l, r);
    if (r > mid)
        modify(2 * p + 1, l, r);
    push_up(p);
}

ll query_sum(int p, int l, int r)
{
    ll res = 0;
    if (l <= t[p].l and r >= t[p].r)
        return t[p].sum;
    int mid = (t[p].l + t[p].r) / 2;
    if (l <= mid)
        res += query_sum(2 * p, l, r);
    if (r > mid)
        res += query_sum(2 * p + 1, l, r);
    return res;
}

ll query_max(int p, int l, int r)
{
    ll res = 0;
    if (l <= t[p].l and r >= t[p].r)
        return t[p].maxn;
    int mid = (t[p].l + t[p].r) / 2;
    if (l <= mid)
        res = std::max(res, query_max(2 * p, l, r));
    if (r > mid)
        res = std::max(res, query_max(2 * p + 1, l, r));
    return res;
}
} // namespace Segment_Tree

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    Segment_Tree::build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (x > y)
            std::swap(x, y);
        switch (opt)
        {
        case 0:
            if (Segment_Tree::query_max(1, x, y) > 1)
                Segment_Tree::modify(1, x, y);
            break;
        case 1:
            printf("%lld\n", Segment_Tree::query_sum(1, x, y));
            break;
        }
    }
    return 0;
}