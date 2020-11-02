#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e6 + 5;

int n;
int a[N];
int last[N], next[N];

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

void write(int x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x >= 10)
        write(x / 10);
    putchar('0' + x % 10);
}

struct HJT_Tree
{
#define mid ((l + r) >> 1)
    int nodecnt, sum[N << 5], L[N << 5], R[N << 5], rt[N];
    void modify(int &p, int pre, int l, int r, int x)
    {
        p = ++nodecnt;
        L[p] = L[pre], R[p] = R[pre], sum[p] = sum[pre] + 1;
        if (l < r)
        {
            if (x <= mid)
                modify(L[p], L[pre], l, mid, x);
            else
                modify(R[p], R[pre], mid + 1, r, x);
        }
    }
    int query(int u, int v, int l, int r, int x, int y)
    {
        if (l == x and y == r)
            return sum[u] - sum[v];
        int res = 0;
        if (x <= mid)
            res += query(L[u], L[v], l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(R[u], R[v], mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
} T;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), last[i] = next[a[i]] + 1, next[a[i]] = i,
        T.modify(T.rt[i], T.rt[i - 1], 1, n, last[i]);
    for (int m = read(); m--;)
    {
        int l = read(), r = read();
        write(T.query(T.rt[r], T.rt[l - 1], 1, n, 1, l)), putchar('\n');
    }
    return 0;
}