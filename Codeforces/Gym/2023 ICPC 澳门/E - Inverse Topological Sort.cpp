#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x, x--;
    for (int &x : b) cin >> x, x--;

    vector<vector<int>> g(n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and stk.back() < a[i]) stk.pop_back();
        if (not stk.empty()) g[stk.back()].eb(a[i]);
        stk.eb(a[i]);
    }
    stk.clear();
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and stk.back() > b[i]) stk.pop_back();
        if (not stk.empty()) g[stk.back()].eb(b[i]);
        stk.eb(b[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     cerr << i << ' ' << g[i] << '\n';
    // }

    std::priority_queue<int> q;

    vector<int> ind(n);
    vector<int> A;
    for (int i = 0; i < n; i++) {
        std::sort(g[i].begin(), g[i].end());
        for (int j : g[i]) {
            // cout << i + 1 << ' ' << j + 1 << '\n';
            ind[j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!ind[i]) {
            q.ep(-i);
            // cerr << "inque: " << i + 1 << '\n';
        }
    }
    while (!q.empty()) {
        int u = -q.top(); q.pop();
        A.eb(u);
        // cerr << "deque: " << u + 1 << '\n';
        for (int v : g[u]) {
            if (!--ind[v]) {
                q.ep(-v);
                // cerr << "inque: " << v + 1 << '\n';
            }
        }
    }

    ind.assign(n, 0);

    vector<int> B;
    for (int i = 0; i < n; i++) {
        std::sort(g[i].rbegin(), g[i].rend());
        for (int j : g[i]) {
            ind[j]++;
        }
    }
    for (int i = n - 1; ~i; i--) {
        if (!ind[i]) {
            q.ep(i);
        }
    }
    while (!q.empty()) {
        int u = q.top(); q.pop();
        B.eb(u);
        for (int v : g[u]) {
            if (!--ind[v]) {
                q.ep(v);
            }
        }
    }

    // cerr << A << '\n';
    // cerr << B << '\n';

    if (a != A or b != B) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            ans.eb(i + 1, j + 1);
        }
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}