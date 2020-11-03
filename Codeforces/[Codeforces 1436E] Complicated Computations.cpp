#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, a[N], vis[N], last[N];

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
#define mid ((l + r) >> 1)
    int min[N << 2];
    void push_up(int p) { min[p] = std::min(min[ls], min[rs]); }
    void modify(int p, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            min[p] = val;
            return;
        }
        if (pos <= mid)
            modify(ls, l, mid, pos, val);
        else
            modify(rs, mid + 1, r, pos, val);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return min[p];
        int res = INF;
        if (x <= mid)
            res = std::min(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::min(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} T;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 1)
            vis[1] = 1;
        if (a[i] != 1)
        {
            int pos = T.query(1, 1, n, 1, a[i] - 1);
            if (pos > last[a[i]])
                vis[a[i]] = 1;
        }
        last[a[i]] = i;
        T.modify(1, 1, n, a[i], i);
    }
    for (int i = 2; i <= n + 1; i++)
    {
        int pos = T.query(1, 1, n, 1, i - 1);
        if (pos > last[i])
            vis[i] = 1;
    }
    int ans = 1;
    while (vis[ans] and ans <= n + 1)
        ans++;
    return printf("%d", ans), 0;
}