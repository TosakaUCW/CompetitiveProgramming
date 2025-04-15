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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> c(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        c[i] = ch == 'R';
    }

    vector<int> red, blk;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) red.eb(a[i]);
        else blk.eb(a[i]);
    }
    sort(red.rbegin(), red.rend());
    sort(blk.rbegin(), blk.rend());

    int m = min(red.size(), blk.size());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += red[i] + blk[i];
    }
    if (red.size() == blk.size()) {

    } else if (m == blk.size()) {
        ans += red[m];
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