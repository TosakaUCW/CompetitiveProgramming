#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
// using namespace std;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

void solve() {
    int n = read();
    int m = 1 << (n + 1);

    vector<int> a(m);
    for (int i = 2; i < m; i++) {
        a[i] = read();
    }
    vector<int> b(m);
    for (int i = 2; i < m; i++) {
        b[i] = b[i >> 1] + a[i];
    }

    // cerr << a << '\n';
    // cerr << b << '\n';

    auto merge = [&](vector<int> a, vector<int> b) -> vector<int> {
        vector<int> c(a.size() + b.size());
        std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        return c;
    };

    vector<vector<vector<int>>> buk(m);

    for (int u = 1 << n; u < m; u++) {
        buk[u].pb({b[u]});
    }

    // cerr << buk << '\n';

    int ans = 0;

    for (int d = n - 1; d >= 0; d--) {
        for (int u = 1 << d; u < 1 << (d + 1); u++) {
            int ls = u << 1;
            int rs = u << 1 | 1;

            for (auto x : buk[ls]) {
                for (auto y : buk[rs]) {
                    auto z = merge(x, y);
                    if (std::unique(z.begin(), z.end()) == z.end()) {
                        buk[u].pb(z);
                    }
                }
            }

            if (buk[u].empty()) {
                ++ans;
                if (ans > n - d) {
                    puts("-1");
                    return;
                }

                for (auto x : buk[ls]) buk[u].pb(x);
                for (auto y : buk[rs]) buk[u].pb(y);
            }
        }
    }

    cerr << buk << '\n';

    cout << ans << '\n';

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}