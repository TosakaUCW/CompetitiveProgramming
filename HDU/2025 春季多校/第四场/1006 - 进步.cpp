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
/**   树状数组（Fenwick 新版）
 *    2023-12-28: https://codeforces.com/contest/1915/submission/239262801
**/
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    Fenwick<int> fen(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fen.add(i - 1, a[i]);
    }

    vector<int> res;

    while (q--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            fen.add(x - 1, y - a[x]);
            a[x] = y;
        } else {
            int r1 = fen.sum(y) / 100;
            int r2 = fen.sum(x - 1) / 100;
            res.eb(r1 - r2);
            // cout << r1 << '/' << r2 << '\n';
        }
    }

    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        ans ^= (i + 1) * res[i];
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
