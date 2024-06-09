#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m, p, ans;
int a[N];
int opt[N], L[N], R[N];

struct Seg_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int tag[N << 2], sum[N << 2];
    void push_up(int p) { sum[p] = sum[ls] + sum[rs]; }
    void push_down(int p, int l, int r)
    {
        if (!tag[p])
            return;
        tag[ls] = tag[rs] = tag[p];
        if (tag[p] == 1)
            sum[ls] = mid - l + 1, sum[rs] = r - mid;
        else
            sum[ls] = sum[rs] = 0;
        tag[p] = 0;
    }
    void build(int p, int l, int r, int x)
    {
        tag[p] = 0;
        if (l == r)
            return sum[p] = a[l] >= x, tag[p] = 0, void();
        build(ls, l, mid, x), build(rs, mid + 1, r, x), push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (x == l and r == y)
            return sum[p];
        push_down(p, l, r);
        int res = 0;
        if (x <= mid)
            res += query(ls, l, mid, x, std::min(mid, y));
        if (mid < y)
            res += query(rs, mid + 1, r, std::max(mid + 1, x), y);
        return res;
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (x > r or y < l)
            return;
        if (x == l and r == y)
            return sum[p] = val * (r - l + 1), tag[p] = val ? 1 : -1, void();
        push_down(p, l, r);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), val);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
#undef ls
#undef rs
#undef mid
} T;

bool judge(int x)
{
    T.build(1, 1, n, x);
    for (int i = 1; i <= m; i++)
    {
        int cnt = T.query(1, 1, n, L[i], R[i]);
        if (opt[i] == 0)
        {
            T.modify(1, 1, n, R[i] - cnt + 1, R[i], 1);
            T.modify(1, 1, n, L[i], R[i] - cnt, 0);
        }
        else
        {
            T.modify(1, 1, n, L[i], L[i] + cnt - 1, 1);
            T.modify(1, 1, n, L[i] + cnt, R[i], 0);
        }
    }
    return T.query(1, 1, n, p, p);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
        opt[i] = read(), L[i] = read(), R[i] = read();
    p = read();
    for (int L = 1, R = n, mid; L <= R;)
        if (judge(mid = L + R >> 1))
            ans = mid, L = mid + 1;
        else
            R = mid - 1;
    return printf("%d", ans), 0;
}