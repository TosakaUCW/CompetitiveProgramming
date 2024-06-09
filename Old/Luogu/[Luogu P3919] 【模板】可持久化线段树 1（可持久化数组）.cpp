#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e6 + 5;

int n, q;
int a[N];

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

struct HJT_Tree
{
#define mid ((l + r) >> 1)
    int nodecnt, rt[N << 5], L[N << 5], R[N << 5], sum[N << 5];
    int build(int l, int r)
    {
        int p = ++nodecnt;
        if (l == r)
        {
            sum[p] = a[l];
            return p;
        }
        else if (l < r)
            L[p] = build(l, mid), R[p] = build(mid + 1, r);
        return sum[p] = sum[L[p]] + sum[R[p]], p;
    }
    int modify(int pre, int l, int r, int pos, int val)
    {
        int p = ++nodecnt;
        L[p] = L[pre], R[p] = R[pre];
        if (l == r)
        {
            sum[p] = val;
            return p;
        }
        else if (l < r)
        {
            if (pos <= mid)
                L[p] = modify(L[pre], l, mid, pos, val);
            else
                R[p] = modify(R[pre], mid + 1, r, pos, val);
        }
        return sum[p] = sum[L[p]] + sum[R[p]], p;
    }
    int query(int p, int l, int r, int pos)
    {
        if (l == r)
            return sum[p];
        if (pos <= mid)
            return query(L[p], l, mid, pos);
        else
            return query(R[p], mid + 1, r, pos);
    }
} T;

int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.rt[0] = T.build(1, n);
    for (int ver, opt, pos, val, i = 1; i <= q; i++)
    {
        ver = read(), opt = read(), pos = read();
        if (opt == 1)
        {
            val = read();
            T.rt[i] = T.rt[ver];
            T.rt[i] = T.modify(T.rt[i], 1, n, pos, val);
        }
        else
            printf("%d\n", T.query(T.rt[ver], 1, n, pos)), T.rt[i] = T.rt[ver];
    }
    return 0;
}