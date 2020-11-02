#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;

int n, q;
int a[N], b[N];

struct HJT_Tree
{
#define mid ((l + r) >> 1)
    int nodecnt, sum[N << 5], L[N << 5], R[N << 5], rt[N << 5];
    int build(int l, int r)
    {
        int p = ++nodecnt;
        if (l < r)
            L[p] = build(l, mid), R[p] = build(mid + 1, r);
        return p;
    }
    int modify(int pre, int l, int r, int x)
    {
        int p = ++nodecnt;
        L[p] = L[pre], R[p] = R[pre], sum[p] = sum[pre] + 1;
        if (l < r)
        {
            if (x <= mid)
                L[p] = modify(L[pre], l, mid, x);
            else
                R[p] = modify(R[pre], mid + 1, r, x);
        }
        return p;
    }
    int query(int u, int v, int l, int r, int k)
    {
        int x = sum[L[v]] - sum[L[u]];
        if (l == r)
            return l;
        if (x < k)
            return query(R[u], R[v], mid + 1, r, k - x);
        else
            return query(L[u], L[v], l, mid, k);
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
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    memcpy(b, a, sizeof b), std::sort(b + 1, b + 1 + n);
    int bn = std::unique(b + 1, b + 1 + n) - b - 1;
    T.rt[0] = T.build(1, bn);
    for (int i = 1; i <= n; i++)
    {
        int k = std::lower_bound(b + 1, b + 1 + bn, a[i]) - b;
        T.rt[i] = T.modify(T.rt[i - 1], 1, bn, k);
    }
    while (q--)
    {
        int l = read(), r = read(), k = read();
        printf("%d\n", b[T.query(T.rt[l - 1], T.rt[r], 1, bn, k)]);
    }
    return 0;
}