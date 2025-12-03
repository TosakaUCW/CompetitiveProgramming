#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;

void solve() {
    int n;
    cin >> n;
    cout.flush();

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        int ls, rs;
        cin >> ls >> rs;
        cout.flush();

        if (ls) {
            g[i].pb(ls);
            g[ls].pb(i);    
        }
        if (rs) {
            g[i].pb(rs);
            g[rs].pb(i);    
        }
    }

    vector<int> siz(n + 1);
    vector<int> w(n + 1);

    int p = 1, tot = n;
    vector<int> ban(n + 1);

    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
        siz[u] = 1;
        for (int v : g[u]) {
            if (ban[v] or v == fa) continue;
            dfs1(v, u);
            siz[u] += siz[v];
        }
    };
    std::function<void(int, int)> dfs2 = [&](int u, int fa) {
        w[u] = 0;
        for (int v : g[u]) {
            if (ban[v] or v == fa) continue;
            dfs2(v, u);
            w[u] = max(w[u], siz[v]);
        }
        w[u] = max(w[u], tot - siz[u]);
        if (w[u] <= tot / 2) {
            p = u;
        }
    };

    using std::endl;
    auto qry = [&](int x, int y) {
        cout << "? " << x << " " << y << endl;
        cout.flush();
        int t; cin >> t;
        cout.flush();
        return t;
    };

    while (tot > 1) {
        dfs1(p, 0);
        tot = siz[p];
        dfs2(p, 0);

        int d = 0;
        for (int v : g[p]) {
            if (!ban[v]) d++;
        }

        if (d == 0) {
            cout << "! " << p << endl;
            cout.flush();
            return;
        } else if (d == 1) {
            int x = p, y = 0;
            for (int tmp : g[p]) {
                if (!ban[tmp]) {
                    y = tmp;
                    break;
                }
            }

            int t = qry(x, y);
            if (t == 0) {
                cout << "! " << x << endl;
                cout.flush();
                return;
            } else if (t == 2) {
                ban[x] = 1;
                p = y;
            }
        } else if (d == 2) {
            int x = 0, y = 0;
            for (int v : g[p]) {
                if (!ban[v]) {
                    if (!x) x = v;
                    else y = v;
                }
            }

            int t = qry(x, y);
            if (t == 0) {
                ban[p] = ban[y] = 1;
                p = x;
            } else if (t == 1) {
                cout << "! " << p << endl;
                cout.flush();
                return;
            } else {
                ban[p] = ban[x] = 1;
                p = y;
            }
            
        } else if (d == 3) {
            int x = g[p][0], y = g[p][1], z = g[p][2];
            int sx = siz[x], sy = siz[y], sz = siz[z];

            if (sx < sy) swap(x, y), swap(sx, sy);
            if (sx < sz) swap(x, z), swap(sx, sz);
            if (sy < sz) swap(y, z), swap(sy, sz);

            int t = qry(x, y);
            if (t == 1) {
                ban[x] = ban[y] = 1;
            } else if (t == 0) {
                ban[y] = ban[z] = ban[p] = 1;
                p = x;
            } else {
                ban[p] = ban[x] = ban[z] = 1;
                p = y;
            }
        }

    }
}

signed main() {
    int T; cin >> T;
    cout.flush();
    for (; T--; solve());
    // solve();
    return 0;
}