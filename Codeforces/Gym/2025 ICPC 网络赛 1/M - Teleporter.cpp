#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
struct Node {
    int x, dis;
    bool friend operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};
void solve() {
    int n = read();
    int m = read();
    
    using pii = pair<int, int>;
    vector<vector<pii>> g(n + 5);
    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();
        int dis = read();
        g[u].emplace_back(v, dis);
        g[v].emplace_back(u, dis);
    }
    const int inf = 1e18;
    vector<pii> path(m);
    for (auto &[x, y] : path) {
        x = read(), y = read();
    }

    vector dis(n + 5, vector(n + 5, inf));
    dis[0][1] = 0;

    vector<int> ans(n + 1);

    for (int k = 0; k <= n; k++) {
        if (k != 0) {
            for (auto [x, y] : path) {
                dis[k][x] = min(dis[k][x], dis[k - 1][y]);
                dis[k][y] = min(dis[k][y], dis[k - 1][x]);
            }
        }
        vector vis(n + 5, 0);
        priority_queue<Node> q;

        for (int i = 1; i <= n; i++) {
            if (dis[k][i] == inf) continue;
            q.push({i, dis[k][i]});
        }
        while (!q.empty()) {
            auto [u, _] = q.top(); q.pop();
            if (vis[u]) continue; 
            vis[u] = 1;
            for (auto [v, w] : g[u]) {
                if (dis[k][u] + w < dis[k][v]) {
                    dis[k][v] = dis[k][u] + w;
                    q.push({v, dis[k][v]});
                }
            }
        }
    }

    for (int k = 0; k <= n; k++) {
        for (int i = 2; i <= n; i++) {
            if (k >= 1) dis[k][i] = min(dis[k][i], dis[k - 1][i]);
            ans[k] += dis[k][i];
        }
        cout << ans[k] << "\n";
    }
}


signed main() {
    solve();
    return 0;
}