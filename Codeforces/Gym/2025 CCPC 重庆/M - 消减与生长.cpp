#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e9;
const double eps = 1e-9;

map<int, int> id;
std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

const int N = 2e5 + 5;
struct Segment {
    struct node { int sum, l, r; };
    vector<node> tr = vector<node>(2);
    #define ls(x) (tr[x].l)
    #define rs(x) (tr[x].r)
    #define sum(x) tr[x].sum  
    int tot = 1;
    void pushup(int x) { sum(x) = sum(ls(x)) + sum(rs(x)); }
    void pushdown(int x) {
        if (!ls(x)) tr.eb(), ls(x) = ++tot;
        if (!rs(x)) tr.eb(), rs(x) = ++tot;
    }
    void upd(int x,int l, int r, int pos, int k) {
        if (l == r) {
            sum(x) += k;
            return;
        }
        int mid = (l + r - 1) / 2;
        pushdown(x);
        if (pos <= mid) upd(ls(x), l, mid, pos, k);
        else upd(rs(x), mid + 1, r, pos, k);
        pushup(x);
    }
    int que(int x, int l, int r, int L, int R) {
        if (L <= l and r <= R) return sum(x);
        if (l > R or r < L) return 0;
        pushdown(x);
        int mid = (l + r - 1) / 2;
        return que(ls(x), l, mid, L, R) + que(rs(x), mid + 1, r, L, R);
    }
    void add(int pos, int k) {
        upd(1, 0, N, pos, k);
    }
    int que(int L,int R) {
        return que(1, 0, N, L, R);
    }
} seg[80000];

void solve() {
    int n = read();
    vector<int> c(n + 1);
    c[1] = read();

    vector<int> qry(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int x = read(), u = read(), v = read();
        qry[i] = u;
        c[i] = x; g[v].eb(i);
    }

    vector<int> siz(n + 1), dep(n + 1), son(n + 1), fa(n + 1), top(n + 1);
    vector<int> dfn(n + 1);
    int timer = 0;
    [&](this auto&& dfs, int u, int f) -> void {
        siz[u] = 1, dep[u] = dep[f] + 1, fa[u] = f;
        for (int v : g[u]) if (v != f) {
            dfs(v, u);
            siz[u] += siz[v];
            son[u] = siz[v] > siz[son[u]] ? v : son[u];
        }
    } (1, 0);
    [&](this auto&& dfs, int u) -> void {
        dfn[u] = ++timer;
        top[u] = u == son[fa[u]] ? top[fa[u]] : u;
        if (son[u]) dfs(son[u]);
        for (int v : g[u]) if (v != fa[u] and v != son[u]) dfs(v);
    } (1);
    auto lca = [&](int x, int y)  {
        for (; top[x] != top[y]; x = fa[top[x]])
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
        return dep[x] < dep[y] ? x : y;
    };
    auto tAdd = [&](int p, int x, int y) -> void {
        seg[id[p]].add(dfn[x], y);
    };
    auto tSum = [&](int p, int x, int y) -> int {
        int res = 0;
        for (; top[x] != top[y]; x = fa[top[x]]) {
            if (dfn[top[x]] < dfn[top[y]]) swap(x, y);
            res += seg[id[p]].que(dfn[top[x]], dfn[x]);
        }
        if (dfn[x] > dfn[y]) swap(x, y);
        res += seg[id[p]].que(dfn[x], dfn[y]);
        return res;
    };


    {
        int x = c[1];
        while (x > 1) {
            int p = minp[x];
            x /= p;
            tAdd(p, 1, 1);
        }
    }

    for (int i = 2; i <= n; i++) {
        int u = qry[i], v = fa[i];
        map<int, int> t;
        for (int x = c[i]; x > 1; ) {
            int p = minp[x];
            t[p]++, x /= p;
        }

        for (auto &[p, c] : t) {
            int k = tSum(p, u, v);
            t[p] = max(t[p] - k, 0ll);
        }

        {
            int x = 1;
            for (auto &[p, c] : t) {
                if (c == 0) continue;
                tAdd(p, i, c);
                for (int k = 1; k <= c; k++) x *= p;
            }
            c[i] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
}

signed main() {
    sieve(1e6);
    for (int p : primes) {
        id[p] = id.size() + 1;
    }
    solve();
    return 0;
}