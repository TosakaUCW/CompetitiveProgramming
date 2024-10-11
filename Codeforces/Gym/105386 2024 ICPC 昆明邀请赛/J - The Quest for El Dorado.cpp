#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int inf = 1e9;

void solve() {
    int n = read(), m = read(), k = read();

    vector g(n + 1, vector<array<int, 3>>());
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        int c = read(), w = read();

        g[u].pb({v, c, w});
        g[v].pb({u, c, w});
    }

    vector<std::array<int, 2>> tik(k + 1);

    vector rmq(m + 1, vector(21, vector<int>()));
    vector pos(m + 1, vector<int>());

    for (int i = 1; i <= k; i++) {
        tik[i][0] = read();
        tik[i][1] = read();

        rmq[tik[i][0]][0].eb(tik[i][1]);
        pos[tik[i][0]].eb(i);
    }

    for (int c = 1; c <= m; c++) {
        for (int j = 1; j <= 20; j++) {
            rmq[c][j].assign(rmq[c][0].size() + 1, 0);
        } 
    }
 
    for (int c = 1; c <= m; c++) {
        for (int j = 1; j <= 20; j++) {
            for (int i = 0; i + (1 << j) - 1 < rmq[c][0].size(); i++) {
                rmq[c][j][i] = max(rmq[c][j - 1][i], rmq[c][j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    auto getrmq = [&](int c, int l, int r) {
        int k = std::__lg(r - l + 1);
        return max(rmq[c][k][l], rmq[c][k][r - (1 << k) + 1]);
    };

    auto search = [&](int l, int c, int len) {
        if (pos[c].empty() or pos[c].back() < l) return -1;

        l = std::lower_bound(pos[c].begin(), pos[c].end(), l) - pos[c].begin();

        int res = -1;
        for (int r = rmq[c][0].size() - 1; l <= r; ) {
            int mid = l + r >> 1;
            if (getrmq(c, l, mid) >= len) {
                res = mid, r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (res == -1) return -1;
        return pos[c][res];
    };

    vector<int> vis(n + 1);
    vector<array<int, 2>> dis(n + 1, {inf, inf});
    std::priority_queue<array<int, 3>, vector<array<int, 3>>, std::greater<>> q;

    dis[1] = {1, 0};
    q.push({1, 0, 1});
    while (!q.empty()) {
        auto [r, d, u] = q.top();
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, c, len] : g[u]) {
            if (tik[r][0] == c and tik[r][1] >= d + len) {
                if (dis[v][0] > r or dis[v][0] == r and dis[v][1] > d + len) {
                    q.push({r, d + len, v});
                }
                continue;
            }

            int nr = search(r + 1, c, len);
            if (nr == -1) continue;
            if (dis[v][0] > nr or dis[v][1] == nr and dis[v][1] > len) {
                q.push({nr, len, v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << vis[i];
    }
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}