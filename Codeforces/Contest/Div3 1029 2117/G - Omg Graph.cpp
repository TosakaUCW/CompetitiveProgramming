#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
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

    vector<vector<pii>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        int w = read();

        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    auto dijkstra = [&](int s) {
        vector<int> dis(n + 1, -inf);
        vector<int> vis(n + 1);
        dis[s] = 0;
        std::priority_queue<Node> q; q.ep(0, s);
        while (!q.empty()) {
            auto [d, u] = q.top(); q.pop();
            if (vis[u]) continue; vis[u] = 1;
            dis[u] = d;
            for (auto [v, w] : g[u]) {
                if (vis[v]) continue;
                // if (dis[v] < w) {
                    q.ep(max(d, w), v);
                // }
            }
        }
        return dis;
    };

    int ans = inf;
    auto d1 = dijkstra(1);
    auto d2 = dijkstra(n);
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : g[u]) {
            ans = min(ans, w + max({d1[u], d2[v], w}));
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}