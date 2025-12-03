#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int inf = 1e18;

struct Node {
    int x, dis;
    bool friend operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

void solve() {
    int n = read();
    int T = read();

    int nod = 2 * n;
    vector<int> a(nod);
    for (int i = 0; i < n; i++) {
        a[i] = read();
        a[i + n] = a[i];
    }

    vector<int> vis(nod);
    vector<int> dis(nod, inf);

    std::priority_queue<Node> q;

    dis[0] = 0;
    q.ep(0, 0);

    auto relax = [&](int u, int v, int dist) {
        if (dis[v] > dis[u] + dist) {
            dis[v] = dis[u] + dist;
            if (!vis[v]) q.ep(v, dis[v]);
        }
    };

    while (!q.empty()) {
        auto [u, _] = q.top();
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        if (u < n) {
            relax(u, (u + a[u]) % n, 1);
            relax(u, n + (u + a[u] + 1) % n, 2);
        } else {
            relax(u, n + (u + a[u]) % n, 1);
            relax(u, n + (u + 1) % n, 1);
        }
    }
    cout << min(dis[T], dis[T + n]);
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}