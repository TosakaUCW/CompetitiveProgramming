#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
constexpr int inf = 1E9;
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    
    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    
    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    
    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

void solve() {
    int n = read(), k = read();

    using pii = std::pair<int, int>;
    #define fi first
    #define se second

    std::unordered_map<int, bool> mp;
    std::map<pii, pii> rules;
    for (int i = 1; i <= k; i++) mp[read()] = 1;

    int sum = 0;
    for (int k = 0; k <= 1; k++)
        for (int i = 1; i < n; i++) {
            int u = read(), v = read(), w = read();
            if (!mp[u] or !mp[v]) continue;
            if (u > v) std::swap(u, v);
            if (k == 0) rules[{u, v}].fi = w;
            else rules[{u, v}].se = w;
            sum += w;
        }

    int node = n;
    int s = ++node;
    int t = ++node;

    int m = rules.size();
    MaxFlow<int> g(n + 2 + m * 2 + 1);

    for (auto [e, w] : rules) {
        auto [u, v] = e;
        auto [w1, w2] = w;

        int i1 = ++node;
        int i2 = ++node;

        g.addEdge(s, i1, w1), g.addEdge(i1, s, 0);
        g.addEdge(i1, u, inf), g.addEdge(u, i1, 0);
        g.addEdge(i1, v, inf), g.addEdge(v, i1, 0);

        g.addEdge(i2, t, w2), g.addEdge(t, i2, 0);
        g.addEdge(u, i2, inf), g.addEdge(i2, u, 0);
        g.addEdge(v, i2, inf), g.addEdge(i2, v, 0);
    }

    int ans = sum - g.flow(s, t);
    cout << ans << '\n';

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}