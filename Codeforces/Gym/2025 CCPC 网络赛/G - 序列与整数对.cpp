#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int m = read();
    
    vector<int> a(n), v;
    vector<pii> q(m);
    for (auto &x : a) {
        x = read();
        v.eb(x);
    }
    for (auto &[x, y] : q) {
        x = read(), y = read();
        v.eb(x), v.eb(y);
    }

    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &x : a) {
        x = ranges::lower_bound(v, x) - v.begin();
    }
    for (auto &[x, y] : q) {
        x = ranges::lower_bound(v, x) - v.begin();
        y = ranges::lower_bound(v, y) - v.begin();
    }

    auto vv = q;
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    map<pii, int> ans;

    int N = v.size();
    vector<vector<int>> buk(N);
    for (int i = 0; i < n; i++) {
        buk[a[i]].eb(i);
    }

    for (auto [x, y] : vv) {
        auto& v1 = buk[x];
        auto& v2 = buk[y];

        if (v1.empty() or v2.empty()) {
            ans[{x, y}] = 0;
            continue;
        }

        int n1 = v1.size();
        int n2 = v2.size();
        int res = 0;

        if (n1 <= n2) {
            for (auto i : v1) {
                int j = ranges::upper_bound(v2, i) - v2.begin();
                res += n2 - j;
            }
        } else {
            for (auto j : v2) {
                int i = ranges::lower_bound(v1, j) - v1.begin();
                res += i;
            }
        }
        
        ans[{x, y}] = res;
    }

    for (auto t : q) cout << ans[t] << '\n';
}

signed main() {
    solve();
    return 0;
}