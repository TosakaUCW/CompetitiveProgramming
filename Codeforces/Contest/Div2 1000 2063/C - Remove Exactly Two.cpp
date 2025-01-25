#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

void solve() {
    int n = read();

    vector<vector<int>> g(n);
    vector<int> d(n);

    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        u--, v--;
        g[u].eb(v), g[v].eb(u);
        d[u]++, d[v]++;
    }

    int mx = ranges::max(d);
    int cnt = ranges::count_if(d, [&](int x) {
        return x == mx; 
    });

    int ans = 0;

    if (cnt >= 3) {
        ans = mx * 2 - 1;
    } else {
        for (int i = 0; i < n; i++) {
            if (d[i] != mx) continue;
            d[i] = 0;
            for (int j : g[i]) d[j]--;
            ans = mx + ranges::max(d) - 1;
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
