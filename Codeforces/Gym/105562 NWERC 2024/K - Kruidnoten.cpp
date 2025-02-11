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
    long double p;
    bool friend operator< (Node a, Node b) {
        return a.d > b.d;
    }
};

void solve() {
    int n = read();
    int m = read();
    int k = read();

    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int u = read() - 1;
        int v = read() - 1;
        int d = read();
        g[u].eb(v, d);
        g[v].eb(u, d);
    }

    vector<Node> a(k);
    for (auto &[_, id, p] : a) {
        cin >> id >> p;
        id--;
    }

    if (ranges::count_if(a, [&](auto x) { return x.p == 1; }) == 0) {
        puts("impossible");
        return;
    }

    auto dijkstra = [&](int s) {
        vector<int> dis(n, inf);
        vector<int> vis(n);
        dis[s] = 0;
        std::priority_queue<Node> q; q.ep(0, s);
        while (!q.empty()) {
            auto [d, u, __] = q.top(); q.pop();
            if (vis[u]) continue; vis[u] = 1;
            for (auto [v, w] : g[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    q.ep(dis[v], v);
                }
            }
        }
        return dis;
    };

    auto dis = dijkstra(0);
    for (auto &[d, id, _] : a) {
        d += dis[id];
    }

    dis = dijkstra(n - 1);
    for (auto &[d, id, _] : a) {
        d += dis[id];
    }

    ranges::sort(a, [&](auto x, auto y) {
        return x.d < y.d;
    });

    long double ans = 0, pre = 1;
    for (auto [dis, id, p] : a) {
        ans += dis * pre * p;
        pre *= (1.0 - p);
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
