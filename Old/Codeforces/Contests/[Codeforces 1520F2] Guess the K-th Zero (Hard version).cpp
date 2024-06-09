#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, t, k, rt, nodecnt;
int lc[N << 2], rc[N << 2], vis[N << 2], sum[N << 2];
#define mid ((l + r) >> 1)

void build(int &p, int l, int r)
{
    if (!p)
        p = ++nodecnt;
    if (l == r)
        return;
    build(lc[p], l, mid), build(rc[p], mid + 1, r);
}

int ask(int x, int y) { return printf("? %d %d\n", x, y), flu, read(); }

int query(int p, int l, int r, int k)
{
    --sum[p];
    if (l == r)
        return l;
    if (!vis[lc[p]])
        vis[lc[p]] = 1, sum[lc[p]] = mid - l + 1 - ask(l, mid);
    return sum[lc[p]] >= k ? query(lc[p], l, mid, k) : query(rc[p], mid + 1, r, k - sum[lc[p]]);
}

signed main()
{
    n = read(), t = read(), build(rt, 1, n);
    for (int i = 1; i <= t; i++)
        printf("! %d\n", query(rt, 1, n, read())), flu;
    return 0;
}