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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    const int INF = m;
    vector<int> pos(k + 1, INF);
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            if (j < pos[t])
                pos[t] = j;
        }

        int mx = 0;
        bool flag = 1;
        for (int c = 1; c <= k; ++c) {
            if (pos[c] == INF) { flag = 0; break; }
            if (pos[c] > mx) mx = pos[c];
        }
        if (!flag) continue;

        ans += (m - (mx + 1) + 1);
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}