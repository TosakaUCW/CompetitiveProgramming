#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N =  1e5 + 5;

int n, cnt, m;
int fa[N], rt[N], lc[N], rc[N], id[N], sum[N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void pushup(int p) { sum[p] = sum[lc[p]] + sum[rc[p]]; }

int add(int p, int x, int y, int pos, int idx)
{
    if (!p) p = ++cnt;
    if (x == y) return id[p] = idx, sum[p]++, p;
    int mid = (x + y) >> 1;
    if (pos <= mid) lc[p] = add(lc[p], x, mid, pos, idx);
    else rc[p] = add(rc[p], mid + 1, y, pos, idx);
    return pushup(p), p;
}

int merge(int a, int b, int x, int y)
{
    if (!a or !b) return a | b;
    if (x == y) 
    {
        if (id[b]) id[a] = id[b], sum[a] += sum[b];
        return a;
    }
    int mid = (x + y) >> 1;
    lc[a] = merge(lc[a], lc[b], x, mid);
    rc[a] = merge(rc[a], rc[b], mid + 1, y);
    return pushup(a), a;
}

int query(int p, int k, int x, int y)
{
    if (sum[p] < k or !p) return 0;
    if (x == y) return id[p];
    int mid = (x + y) >> 1;
    return k <= sum[lc[p]] ? query(lc[p], k, x, mid) : query(rc[p], k - sum[lc[p]], mid + 1, y);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1, x; i <= n; i++) 
        fa[i] = i, x = read(), rt[i] = add(rt[i], 1, n, x, i);
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        x = find(x), y = find(y);
        if (x == y) continue;
        fa[y] = x, rt[x] = merge(rt[x], rt[y], 1, n);
    }
    for (int q = read(); q--; )
    {
        char ch; int x, y;
        scanf("%s", &ch);
        if (ch == 'Q') 
        {
            x = read(), y = read();
            x = find(x);
            int ans = query(rt[x], y, 1, n);
            printf("%d\n", ans ? ans : -1);
        }
        else
        {
            x = read(), y = read();
            x = find(x), y = find(y);
            if (x == y) continue;
            fa[y] = x;
            rt[x] = merge(rt[x], rt[y], 1, n);
        }
    }
    return 0;
}
