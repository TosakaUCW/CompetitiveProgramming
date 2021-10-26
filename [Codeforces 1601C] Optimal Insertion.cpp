#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m, ans, len;
int b[N], c[N];
std::pair<int, int> a[N];

#define fi first
#define se second

void add(int x)
{
    for (; x; x -= (x & -x))
        c[x]++;
}

int ask(int x)
{
    int res = 0;
    for (; x <= n; x += (x & -x))
        res += c[x];
    return res;
}

struct Seg_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int min[N << 2], tag[N << 2];
    void pushdown(int p)
    {
        if (!tag[p])
            return;
        min[ls] += tag[p], min[rs] += tag[p];
        tag[ls] += tag[p], tag[rs] += tag[p];
        tag[p] = 0;
    }
    void build(int p, int l, int r)
    {
        tag[p] = 0;
        if (l == r)
            return min[p] = l, void();
        build(ls, l, mid), build(rs, mid + 1, r), min[p] = std::min(min[ls], min[rs]);
    }
    void add(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
            return min[p] += k, tag[p] += k, void();
        pushdown(p);
        if (x <= mid)
            add(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            add(rs, mid + 1, r, std::max(x, mid + 1), y, k);
        min[p] = std::min(min[ls], min[rs]);
    }
} T;

void solve()
{
    n = read(), m = read(), ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = {read(), i}, c[i] = 0;
    for (int i = 1; i <= m; i++)
        b[i] = read();
    T.build(1, 0, n);
    std::sort(a + 1, a + 1 + n), std::sort(b + 1, b + 1 + m);
    for (int i = 1, j = 1, k = 1; i <= m; i++)
    {
        for (; a[j].fi <= b[i] and j <= n; j++)
            T.add(1, 0, n, a[j].se, n, -1);
        for (; a[k].fi < b[i] and k <= n; k++)
            T.add(1, 0, n, 0, a[k].se - 1, 1);
        ans += T.min[1];
    }
    for (int i = 1, j = 1; i <= n; i++)
    {
        for (; a[j].fi < a[i].fi; j++)
            add(a[j].se);
        ans += ask(a[i].se);
    }
    printf("%lld\n", ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}