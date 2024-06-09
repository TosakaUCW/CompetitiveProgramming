#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define pb push_back
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e5 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, k, m, ans, buf[N], ind[N];
int l[N], r[N];
int max[N << 2], tag[N << 2];
std::vector<std::pair<int, int>> seg;
int query(int p, int l, int r, int x, int y)
{
    if (x <= l and r <= y) return max[p];
    int res = 0;
    if (tag[p]) max[ls] += tag[p], max[rs] += tag[p], tag[ls] += tag[p], tag[rs] += tag[p], tag[p] = 0;
    max[p] = std::max(max[ls], max[rs]);
    if (y <= mid) return query(ls, l, mid, x, y);
    if (x > mid) return query(rs, mid + 1, r, x, y);
    return std::max(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}
void modify_assign(int p, int l, int r, int x, int k)
{
    if (l == r) { max[p] = k; return; }
    if (tag[p]) max[ls] += tag[p], max[rs] += tag[p], tag[ls] += tag[p], tag[rs] += tag[p], tag[p] = 0;
    if (x <= mid) modify_assign(ls, l, mid, x, k);
    else modify_assign(rs, mid + 1, r, x, k);
    max[p] = std::max(max[ls], max[rs]);
}
void modify_add(int p, int l, int r, int x, int y, int k)
{
    if (x <= l and r <= y) { max[p] += k, tag[p] += k; return; }
    if (tag[p]) max[ls] += tag[p], max[rs] += tag[p], tag[ls] += tag[p], tag[rs] += tag[p], tag[p] = 0;
    if (x <= mid) modify_add(ls, l, mid, x, y, k);
    if (mid < y) modify_add(rs, mid + 1, r, x, y, k);
    max[p] = std::max(max[ls], max[rs]);
}
void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        int l = std::max(0, read()) + 1, r = read() + 1;
        if (r < 1) continue;
        seg.pb({l, r}), ind[l]++, buf[l]++, buf[r + 1]--, m = std::max(m, r + 1);
    }
    std::sort(seg.begin(), seg.end());
    for (int i = 1, now = 0, p = 0, res; i <= m; i++)
    {
        buf[i] += buf[i - 1];
        res = buf[i] + query(1, 0, m, std::max(0, i - 2 * k), std::max(0, i - k));
        ans = std::max(ans, res), now += ind[i];
        for (modify_assign(1, 0, m, i, res - now); p < seg.size() and seg[p].se == i; p++)
            --now, modify_add(1, 0, m, seg[p].fi, seg[p].se, 1);
    }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}