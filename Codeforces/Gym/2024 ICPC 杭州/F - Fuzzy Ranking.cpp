#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n = read(), k = read(), q = read();

    vector a(k, vector<int>(n));

    SCC scc(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = read() - 1;
            if (j > 0) {
                g[a[i][j - 1]].eb(a[i][j]);
                scc.addEdge(a[i][j - 1], a[i][j]);
            }
        }
    }

    auto calc = [&](int x) {
        return x * (x - 1) / 2;
    };

    auto bel = scc.work();
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[bel[i]]++;
    }
    vector sum(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {

            int pre = a[i][j - 1];
            int now = a[i][j];
            if (bel[now] != bel[pre]) {
                sum[i][j - 1] += calc(cnt[bel[pre]]);
            }

            sum[i][j] += sum[i][j - 1];
        }
        sum[i][n - 1] += calc(cnt[bel[a[i][n - 1]]]);
    }

    // cerr << bel << '\n';
    // cerr << cnt << '\n';

    for (int las = 0; q--; ) {
        int id = (read() + las) % k;
        int x = (read() + las) % n;
        int y = (read() + las) % n;
        // cerr << "query: " << id << ' ' << x << ' ' << y << '\n';

        int ans = 0;

        int l = x;
        for (int L = x, R = y; L <= R; ) {
            int mid = L + R >> 1;
            if (bel[a[id][mid]] == bel[a[id][x]]) {
                l = mid, L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        int r = y;
        for (int L = x, R = y; L <= R; ) {
            int mid = L + R >> 1;
            if (bel[a[id][mid]] == bel[a[id][y]]) {
                r = mid, R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        // [x, l] same
        // [l + 1, r - 1] diff
        // [r, y] same
        if (l > r) {
            // int t = min(cnt[bel[a[id][x]]], y - x + 1);
            int t = y - x + 1;
            ans += t * (t - 1) / 2;
            // cout << "t: " << cnt[bel[a[id][x]]] << '\n';
        } else {
            // cerr << sum[id] << '\n';
            if (l + 1 <= r - 1) {
                ans += sum[id][r - 1];
                ans -= sum[id][l];
            }
            ans += (l - x + 1) * (l - x) / 2;
            ans += (y - r + 1) * (y - r) / 2;
        }

        // cerr << "l, r: " << l << ' ' << r << '\n';

        cout << ans << '\n';
        las = ans;
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
