#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
const int inf = 1e9;
using pii = std::pair<int, int>;
#define fi first
#define se second
int a[4];

struct Node {
    int dis, u;
    bool friend operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

signed main() {
    int T = read();
    for (int i = 0; i < 4; i++) a[i] = read();

    const int opt[] = {1, 2, 4, 8, 12, 3, 10, 5, 15};
    const int val[] = {a[0], a[0], a[0], a[0], a[1], a[1], a[2], a[2], a[3]};

    int N = 1 << 16;

    vector<vector<pii>> g(N);

    for (int s = 0; s < N; s++) {

        for (int i = 0; i < 9; i++) {
            int t = 0;
            for (int bit = 0; bit < 16; bit++) {
                if (!(s >> bit & 1)) continue;
                int u = bit;
                int v = u ^ opt[i];
                if (v != 15) t |= (1 << v);
            }
            g[t].eb(s, val[i]);
        }
    }

    vector<int> dis(N, inf);
    vector<int> vis(N, 0);

    int st = 0;
    std::priority_queue<Node> q;
    dis[st] = 0, q.ep(0, st);
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        // cout << "u : " << u << '\n';
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            // cout << "v w : " << v << " " << w << "\n";
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.ep(dis[v], v);
            }
        }
    }

    while (T--) {
        int n = read();
        int sta = 0;
        for (int i = 0; i < n; i++) {
            string s, t;
            cin >> s >> t;
            int x = (s[0] - '0') * 8 + (s[1] - '0') * 4
                  + (t[0] - '0') * 2 + (t[1] - '0');
            // cout << a[i] << '\n';
            sta |= (1 << x);
        }
        // cout << sta << '\n';
        cout << dis[sta] << '\n';
    }
    return 0;
}