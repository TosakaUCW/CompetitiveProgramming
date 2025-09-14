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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct Node {
    int x, f, g;
    bool friend operator < (Node a, Node b) {
        if (a.f != b.f) return a.f > b.f;
        return a.g > b.g;
    }
};
void solve() {
    int n = read();
    int m = read();
    int V = read();
    int T = read();
    
    using pii = pair<int, int>;
    vector<vector<pii>> g(n + 1);
    const int inf = 1e18;
    vector<pii> path(m);
    for (int i = 0; i < m; i++) {
        int x = read(), y = read(), w = read();
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }

    vector<int> dis(n + 1, inf), vis(n + 1);
    vector<int> F(n + 1, inf), G(n + 1, inf);

    F[T] = 1, G[T] = 0;
    priority_queue<Node> q;
    q.push({T, 0}); dis[T] = 0;

    while (!q.empty()) {
        auto [u, _, __] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            int nG = G[u] + w;
            int nF = F[u];
            if (nG > V) nG = w, nF++;
            if (nF < F[v] or (nF == F[v] and nG < G[v])) {
                F[v] = nF, G[v] = nG;
                q.push({v, F[v], G[v]});
            }

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (dis[i] == inf) ans[i] = -1;
        else ans[i] = F[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}


signed main() {
    solve();
    return 0;
}