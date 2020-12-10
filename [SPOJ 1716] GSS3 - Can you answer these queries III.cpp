#include <stdio.h>
#include <algorithm>

const int N = 5e4 + 5;

int n, m, a[N];

namespace Segment_Tree
{
struct Node
{
    int l, r;
    int pre, suf;
    int sum, maxn;
} t[4 * N];

void push_up(int p)
{
    int res = 0;
    t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;
    t[p].maxn = std::max(t[2 * p].maxn, t[2 * p + 1].maxn);

    res = t[2 * p].suf + t[2 * p + 1].pre;
    t[p].maxn = std::max(t[p].maxn, res);

    res = t[2 * p].sum + t[2 * p + 1].pre;
    t[p].pre = std::max(t[2 * p].pre, res);

    res = t[2 * p].suf + t[2 * p + 1].sum;
    t[p].suf = std::max(t[2 * p + 1].suf, res);
}

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].sum = t[p].maxn = a[l];
        t[p].pre = t[p].suf = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid), build(2 * p + 1, mid + 1, r);
    push_up(p);
}

Node merge(Node a, Node b)
{
    Node res;
    res.sum = a.sum + b.sum;
    res.maxn = std::max(a.maxn, std::max(b.maxn, a.suf + b.pre));
    res.pre = std::max(a.pre, a.sum + b.pre);
    res.suf = std::max(b.suf, a.suf + b.sum);
    return res;
}

Node query(int p, int l, int r)
{
    if (l <= t[p].l and r >= t[p].r)
        return t[p];
    int mid = (t[p].l + t[p].r) / 2;
    if (l > mid)
        return query(2 * p + 1, l, r);
    if (r <= mid)
        return query(2 * p, l, r);
    Node a = query(2 * p, l, r);
    Node b = query(2 * p + 1, l, r);
    return merge(a, b);
}

void modify(int p, int x, int val)
{
    if (t[p].l == t[p].r)
    {
        t[p].sum = t[p].maxn = val;
        t[p].pre = t[p].suf = val;
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid)
        modify(2 * p, x, val);
    else
        modify(2 * p + 1, x, val);
    push_up(p);
}
} // namespace Segment_Tree

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Segment_Tree::build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        switch (opt)
        {
        case 0:
            Segment_Tree::modify(1, x, y);
            break;
        case 1:
            printf("%d\n", Segment_Tree::query(1, x, y).maxn);
            break;
        }
    }
    return 0;
}