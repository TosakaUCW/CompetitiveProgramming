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
const int INF = 1e18;
void solve() {
    int n = read();
    int m = read();
    int x = read();
    int y = read();
    vector<int> a(n);
    for (auto &x : a) x = read();
    std::ranges::sort(a);
    vector<int> b(m);
    for (auto &x : b) x = read();
    std::ranges::sort(b);

    auto judge = [&](int lim) {
        // [1, lim]
        vector t(n, x);
        for (int i = 0; i < lim; i++) {
            t[i] = y;
        }

        int p = 0;
        for (auto x : b) {
            if (t[p] > 0 and a[p] >= x) {
                t[p]--;
            } else {
                while (p < n and (a[p] < x or !t[p])) p++;
                if (p >= n) return 0;
                t[p]--;
            }
        }
        return 1;
    };

    int ans = -1;
    for (int L = 0, R = n; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) {
            ans = mid, L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    if (ans == -1) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
