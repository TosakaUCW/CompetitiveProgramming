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
    int k, b, c, v;
    cin >> k >> b >> c >> v;

    // p = kx + b
    // (kx + b) ^ c <= v

    auto get = [&](int l, int r) {
        // l <= kx + b <= r
        int lo = (l - b - 1) / k;
        int hi = (r - b) / k;
        if (lo < 0) lo = 0;
        if (hi < 0) hi = 0;
        return hi - lo;
    };
    auto go = [&](auto self, int d, int cur) {
        if (d == -1) return get(cur, cur);

        int xv = (v >> d) & 1ll, xc = (c >> d) & 1ll;
        int t = 1ll << d;
        int nd = d - 1ll;
        int ncur = cur | t;

        int res = 0;
        if (xv == 0 and xc == 0) {
            // p[d] = 0
            res += self(self, nd, cur);
        }
        if (xv == 0 and xc == 1) {
            // p[d] = 1
            res += self(self, nd, ncur);
        }
        if (xv == 1 and xc == 0) {
            // p[d] = 0
            res += get(cur, ncur - 1ll);
            // p[d] = 1
            res += self(self, nd, ncur);
        }
        if (xv == 1 and xc == 1) {
            // p[d] = 1
            res += get(ncur, cur | ((t << 1) - 1ll));
            // p[d] = 0
            res += self(self, nd, cur);
        }
        return res;
    };

    int ans = go(go, 60, 0) + ((b ^ c) <= v);
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