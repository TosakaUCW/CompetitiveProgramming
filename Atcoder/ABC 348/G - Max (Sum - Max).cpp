#include <bits/stdc++.h>
using i64 = long long;
#define int long long
#define fi first
#define se second
#define mid (l + r >> 1)
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
const i64 INF = 1LL << 60;

int n, a[N], b[N], f[N], g[N];
vector<int> d;

struct Node
{
    int num, ls, rs, sum;
} t[N * 25];
int rt[N], idx;

void build(int &p, int l, int r)
{
    p = ++idx;
    if (l == r) return;
    build(t[p].ls, l, mid);
    build(t[p].rs, mid + 1, r); 
}

void insert(int x, int &y, int l, int r, int id, int v)
{
    y = ++idx, t[y] = t[x];
    t[y].num++, t[y].sum += v;
    if (l == r) return;
    if (id <= mid) insert(t[x].ls, t[y].ls, l, mid, id, v);
    else insert(t[x].rs, t[y].rs, mid + 1, r, id, v);
}

int query(int p, int l, int r, int k)
{
    if (l == r) return k * d[l - 1];
    int num = t[t[p].rs].num;
    if (k <= num) return query(t[p].rs, mid + 1, r, k);
    else return query(t[p].ls, l, mid, k - num) + t[t[p].rs].sum;
}

void divide(int l, int r, int optl, int optr)
{
    int optm = optl;
    f[mid] = g[mid];
    for (int i = std::max(optl, mid); i <= optr; i++)
    {
        int tmp = query(rt[i - 1], 1, n, mid - 1) + a[i] - b[i];
        if (tmp > f[mid]) f[mid] = tmp, optm = i;
    }
    g[mid] = f[mid];
    if (l < mid) divide(l, mid, optl, optm);
    if (mid < r) divide(mid + 1, r, optm, optr);
}

void solve()
{
    n = read();
    build(rt[0], 1, n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(), d.pb(a[i]);
    std::sort(d.begin(), d.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());

    vector<int> id(n + 1);
    vector<pii> res(n + 1);
    for (int i = 1; i <= n; i++) res[i] = {b[i], a[i]}, g[i] = -INF;
    std::sort(res.begin() + 1, res.end());
    for (int i = 1; i <= n; i++) a[i] = res[i].se, b[i] = res[i].fi;
    for (int i = 1; i <= n; i++) id[i] = std::lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
    for (int i = 1; i <= n; i++) insert(rt[i - 1], rt[i], 1, n, id[i], a[i]);
    divide(1, n, 1, n);
    for (int i = 1; i <= n; i++) cout << f[i] << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}