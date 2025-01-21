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
const int N = 1e7;

void solve() {
    int n = read();
    int m = read();
    int k = read();

    vector<int> a(n);
    for (auto &x : a) x = read();

    vector<int> b(m);
    for (auto &x : b) x = read();

    int all = 1 << m;
    int ans = std::accumulate(a.begin(), a.end(), 0ll);

    vector<int> c(all);
    for (int i = 0; i < all; i++) {
        c[i] = (1 << 30) - 1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                c[i] &= b[j];
            }
        }
    }

    vector f(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < all; j++) {
            int k = __builtin_popcountll(j);
            f[i][k] = max(f[i][k], a[i] - (a[i] & c[j]));
        }
    }

    std::priority_queue<pii> q;
    vector<int> d(n);
    for (int i = 0; i < n; i++) q.ep(f[i][1], i);

    while (k--) {
        auto [v, i] = q.top(); q.pop();

        ans -= v;
        ++d[i];
        if (d[i] < m) q.ep(f[i][d[i] + 1] - f[i][d[i]], i);
    }


    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
