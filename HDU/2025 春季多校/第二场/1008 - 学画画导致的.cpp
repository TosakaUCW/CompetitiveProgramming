#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> g(3 * n + 1);
    vector<int> ind(3 * n + 1);
    bool f = 1;

    for (int i = 0; i < m; i++) {
        int x, y, col;
        cin >> x >> y >> col;
        array<int, 3> a = {(y + 1) / 2, 2 * n - x + 1, 2 * n + x - y / 2};
        if (a[1] == col) swap(a[1], a[0]);
        if (a[2] == col) swap(a[2], a[0]);
        if (a[0] != col) f = 0;
        g[a[1]].eb(col), g[a[2]].eb(col);
        ind[col] += 2;
    }

    if (!f) { cout << "No\n"; return; }

    queue<int> q; 
    for (int i = 1; i <= 3 * n; i++) {
        if (!ind[i]) {
            q.ep(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) { 
            ind[v]--; 
            if (!ind[v]) q.ep(v); 
        }
    }
    for (int i = 1; i <= 3 * n; i++) {
        if (ind[i]) { cout << "No\n"; return; }
    }
    cout << "Yes\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}