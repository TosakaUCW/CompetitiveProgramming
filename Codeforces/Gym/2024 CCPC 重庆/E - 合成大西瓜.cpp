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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

double eps = 1e-7;
const int inf = 1e18;

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> ind(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].eb(v), g[v].eb(u);
        ind[u]++, ind[v]++;
    }

    int ans = 0;
    pii res = {0, 0};
    for (int i = 0; i < n; i++) {
        if (ind[i] == 1) {
            if (a[i] >= res.fi) {
                res = {a[i], res.fi};
            } else if (a[i] > res.se) {
                res.se = a[i];
            }
        }
        else ans = max(ans, a[i]);
    }
    if (res.se != inf) ans = max(ans, res.se);

    cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int T; cin >> T;
    // for (; T--; solve());
    solve();
    return 0;
}
