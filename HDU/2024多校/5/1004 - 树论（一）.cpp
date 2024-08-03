#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int MX = 1e5;

i64 lcm(int x, int y) { return 1LL * x * y / std::__gcd(x, y); }

vector<int> divs[N];
vector<std::pair<int, int>> pos[N];

void solve() {
    int n = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }

    vector<int> siz(n + 1), dep(n + 1), son(n + 1), fa(n + 1), top(n + 1);
    vector<int> dfn(n + 1);
    int timer = 0;
    std::function<void(int, int)> dfs1 = [&](int u, int f) {
        siz[u] = 1, dep[u] = dep[f] + 1, fa[u] = f;
        for (int v : g[u]) if (v != f) {
            dfs1(v, u);
            siz[u] += siz[v];
            son[u] = siz[v] > siz[son[u]] ? v : son[u];
        }
    };
    std::function<void(int)> dfs2 = [&](int u) {
        dfn[u] = ++timer;
        top[u] = u == son[fa[u]] ? top[fa[u]] : u;
        if (son[u]) dfs2(son[u]);
        for (int v : g[u]) if (v != fa[u] and v != son[u]) dfs2(v);
    };

    dfs1(1, 0), dfs2(1);

    int Q = read();
    using arr = std::array<int, 4>;
    vector<arr> q(Q + 1);
    vector<int> ans(Q + 1);
    for (int i = 1; i <= Q; i++) q[i][0] = read(), q[i][1] = read(), q[i][2] = i;
    std::sort(q.begin() + 1, q.end(), [](arr x, arr y) { return x[1] < y[1]; });

    auto LCA = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (fa[top[u]] < fa[top[v]]) std::swap(u, v);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        return u;
    };

    vector<int> t(n + 1);
    #define lb(x) (x & -x)
    auto add = [&](int x, int v) {
        for (; x <= n; x += lb(x)) t[x] += v;
    };
    auto query = [&](int x) {
        int res = 0;
        for (; x; x -= lb(x)) res += t[x];
        return res;
    };
    auto Query = [&](int l, int r) { return query(r) - query(l - 1); };

    int L = 0;
    for (int i = 1; i <= Q; i++) {
        while (L < q[i][1]) {
            L++;
            for (auto [i, j] : pos[L])
                if (i <= n) 
                    add(dfn[LCA(i, j)], 1 + (i != j));
        }
        ans[q[i][2]] = Query(dfn[q[i][0]], dfn[q[i][0]] + siz[q[i][0]] - 1);
    }

    for (int i = 1; i <= Q; i++) cout << ans[i] << " \n"[i == Q];
}

signed main() {
    for (int i = 1; i <= MX; i++) {
        for (int j = i; j <= MX; j += i) {
            divs[j].pb(i);
        }
    }

    for (int i = 1; i <= MX; i++) {
        for (int LCM = i; LCM <= MX; LCM += i) {
            for (auto j : divs[LCM]) {
                if (j <= i and lcm(i, j) == LCM) {
                    pos[LCM].pb({i, j});
                }
            }
        }
    }

    for (int T = read(); T--; solve());
    // solve();
    return 0;
}