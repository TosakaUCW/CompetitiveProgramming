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

const int N = 1e5 + 5;
const int P = 998244353;

int n, m, a[N], las[N], ans[N];
int rt[N], ch[N * 400][2], cnt[N * 400], nodecnt;
struct Node
{
    int l, a, b, idx;
};
vector<Node> Q[N];

void ins(int &p, int v, int x)
{
    if (!p)
        p = ++nodecnt;
    int now = p;
    for (int i = 20; i >= 0; i--)
    {
        int t = x >> i & 1;
        if (!ch[now][t])
            ch[now][t] = ++nodecnt;
        now = ch[now][t], cnt[now] += v;
    }
}

int query(int p, int a, int b)
{
    int res = 0;
    for (int i = 20; i >= 0; i--)
    {
        int x = a >> i & 1;
        int y = b >> i & 1;
        if (y)
        {
            if (x)
                res += cnt[ch[p][1]], p = ch[p][0];
            else
                res += cnt[ch[p][0]], p = ch[p][1];
        }
        else
            p = ch[p][x];
        if (!p)
            break;
    }
    return res + cnt[p];
}

void add(int x, int v, int y)
{
    for (; x <= n; x += x & -x)
        ins(rt[x], v, y);
}

int ask(int x, int a, int b)
{
    int res = 0;
    for (; x; x -= x & -x)
        res += query(rt[x], a, b);
    return res;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read(), a = read(), b = read();
        Q[r].pb({l, a, b, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (las[a[i]])
            add(las[a[i]], -1, a[i]);
        add(i, 1, a[i]), las[a[i]] = i;
        for (auto x : Q[i])
            ans[x.idx] = ask(i, x.a, x.b) - ask(x.l - 1, x.a, x.b);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}