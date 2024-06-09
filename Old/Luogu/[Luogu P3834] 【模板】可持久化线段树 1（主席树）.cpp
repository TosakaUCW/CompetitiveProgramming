#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 2e5 + 5;

int n, m, bn;
int a[N], b[N], T[N << 5];

struct Segment_Tree
{
    int Nodecnt;
    int L[N << 5], R[N << 5], sum[N << 5];

    int build(int l, int r)
    {
        int p = ++Nodecnt;
        sum[p] = 0;
        if (l < r)
        {
            int mid = (l + r) / 2;
            L[p] = build(l, mid);
            R[p] = build(mid + 1, r);
        }
        return p;
    }

    int modify(int pre, int l, int r, int x)
    {
        int p = ++Nodecnt;
        L[p] = L[pre], R[p] = R[pre];
        sum[p] = sum[pre] + 1;
        if (l < r)
        {
            int mid = (l + r) / 2;
            if (x <= mid)
                L[p] = modify(L[pre], l, mid, x);
            else
                R[p] = modify(R[pre], mid + 1, r, x);
        }
        return p;
    }

    int query(int u, int v, int l, int r, int k)
    {
        if (l >= r)
            return l;
        int mid = (l + r) / 2;
        int x = sum[L[v]] - sum[L[u]];

        if (x >= k)
            return query(L[u], L[v], l, mid, k);
        else
            return query(R[u], R[v], mid + 1, r, k - x);
    }
} SegTree;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    bn = std::unique(b + 1, b + n + 1) - b - 1;
    T[0] = SegTree.build(1, bn);
    for (int i = 1; i <= n; i++)
    {
        int t = std::lower_bound(b + 1, b + 1 + bn, a[i]) - b;
        T[i] = SegTree.modify(T[i - 1], 1, bn, t);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int t = SegTree.query(T[l - 1], T[r], 1, bn, k);
        printf("%d\n", b[t]);
    }
    return 0;
}