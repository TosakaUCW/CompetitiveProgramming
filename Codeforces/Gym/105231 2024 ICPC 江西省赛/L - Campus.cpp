#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct Node {
    int d, id;
    bool friend operator< (Node a, Node b) {
        return a.d > b.d;
    }
};

void solve() {
    int n = read();
    int m = read();
    int k = read();
    int T = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<vector<pii>> g(n + 1);
    vector<vector<int>> st(T + 2), ed(T + 2);
    vector<int> open(n + 1);

    for (int i = 1; i <= k; i++) {
        int p = read();
        int l = read(), r = read();
        // open[p] = {l, r};
        g[0].eb(p, 0);
        g[p].eb(0, 0);
        st[l].eb(p);
        ed[r + 1].eb(p);
    }
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        int w = read();
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    auto dijkstra = [&](int s) {
        vector<int> dis(n + 1, inf);
        vector<int> vis(n + 1);
        dis[s] = 0;
        std::priority_queue<Node> q; q.ep(0, s);
        while (!q.empty()) {
            auto [d, u] = q.top(); q.pop();
            if (vis[u]) continue; vis[u] = 1;
            for (auto [v, w] : g[u]) {
                if (u == 0 and !open[v]) continue;
                if (v == 0 and !open[u]) continue;
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    q.ep(dis[v], v);
                }
            }
        }
        return dis;
    };

    int res = -1;
    for (int i = 1; i <= T; i++) {
        for (auto x : ed[i]) open[x] = 0;
        for (auto x : st[i]) open[x] = 1;

        if (ed[i].empty() and st[i].empty()) {

        } else {
            auto dis = dijkstra(0);
            res = 0;
            for (int i = 1; i <= n; i++) {
                res += dis[i] * a[i];
                if (dis[i] == inf) { res = -1; break; }
            }
        }
        
        cout << res << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}