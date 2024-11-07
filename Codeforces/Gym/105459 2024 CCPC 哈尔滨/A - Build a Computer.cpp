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

void solve() {
    int L = read();
    int R = read();

    vector<int> d(1000);
    
    int st = 1;
    int ed = 2;
    d[0] = ed;

    using pii = std::pair<int, int>;
    vector<vector<pii>> g(1000);

    for (int i = 1; i <= 20; i++) {
        d[i] = ed + i;

        g[d[i]].eb(d[i - 1], 0);
        g[d[i]].eb(d[i - 1], 1);
    }

    int cur = 22; // 20(log) + 1(st) + 1(ed)
    vector ts(1000, vector<int>(2, -1));

    auto get_id = [&](int p) {
        vector<int> s;
        for (; p; p >>= 1) s.eb(p % 2);
        std::reverse(s.begin(), s.end());
        // for (auto x : s) printf("%d", x);puts("");
        int now = st;
        for (auto x : s) {
            if (ts[now][x] == -1) {
                ts[now][x] = ++cur;
                // printf("add %d %d %d\n", now, cur, x);
                g[now].eb(cur, x);
            }
            now = ts[now][x];
        }
        return now;
    };

    auto cons = [&](this auto &&self, int l, int r, int lb, int rb, int lv, int p) -> void {
        if (l == lb and r == rb) {
            int w = 0, f = p / 2;
            if (f * 2 + 1 == p) {
                w = 1;
            }

            int id = get_id(f);
            g[id].eb(d[lv], w);
            return;
        }
        int mid = lb + rb >> 1;
        if (r <= mid) {
            self(l, r, lb, mid, lv - 1, p * 2);
        } else if (mid < l) {
            self(l, r, mid + 1, rb, lv - 1, p * 2 + 1);
        } else {
            self(l, mid, lb, mid, lv - 1, p * 2);
            self(mid + 1, r, mid + 1, rb, lv - 1, p * 2 + 1);
        }
        return;
    };

    cons(L, R, 0, (1 << 20) - 1, 20, 0);

    // for (int i = 1; i <= cur; ++i) {
    //     printf("Node %d:  ", i);
    //     for (auto v : g[i]) 
    //         printf("%d|%d ", v.first, v.second); 
    //     puts("");
    // }

    int n = 1;
    std::map<int, int> idx;
    idx[1] = 1;
    vector<int> vis(1000);
    auto dfs = [&](this auto &&self, int u) -> void {
        vis[u] = 1;
        for (auto [v, dis] : g[u]) {
            if (vis[v]) continue;
            self(v);
        }
    };
    dfs(1);
    for (int i = 2; i <= cur; i++) {
        if (!vis[i]) continue;
        idx[i] = ++n;
    }

    vector<vector<pii>> G(1000);
    for (int i = 1; i <= cur; i++) {
        if (!vis[i]) continue;
        for (auto [j, dis] : g[i]) {
            int u = idx[i];
            int v = idx[j];
            G[u].eb(v, dis);
        }
    }

    cout << n << '\n';
    for (int u = 1; u <= n; u++) {
        cout << G[u].size();
        for (auto [v, dis] : G[u]) {
            cout << " " << v;
            cout << " " << dis;
        }
        cout << '\n';
    }

}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}