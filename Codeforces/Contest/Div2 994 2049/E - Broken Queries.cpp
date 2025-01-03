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

void solve() {
    int n; cin >> n; fflush(stdout);

    auto ask = [&](int l, int r) {
        cout << "? " << l << " " << r << "\n";
        fflush(stdout);
        int res; cin >> res; fflush(stdout);
        return res;
    };

    int ans = 0;

    if (ask(1, n / 4) != ask(n / 4 + 1, n / 2)) {
        // 1 in [1, n / 2]
        // sum[1, n / 2] = 1
        // sum(n / 2, n] = 0
        if (ask(1, n / 2) == 1) {
            // k > n / 2
            for (int l = n / 2 + 1, r = n - 1; l <= r; ) {
                int mid = l + r >> 1;
                if (ask(1, mid) == 0) {
                    ans = mid, r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        } else {
            // k <= n / 2
            for (int l = 2, r = n / 2; l <= r; ) {
                int mid = l + r >> 1;
                if (ask(n / 2 + 1, n / 2 + mid) == 1) {
                    ans = mid, r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    } else {
        // 1 in (n / 2, n]
        // sum[1, n / 2] = 0
        // sum(n / 2, n] = 1
        if (ask(1, n / 2) == 0) {
            // k > n / 2
            for (int l = n / 2 + 1, r = n - 1; l <= r; ) {
                int mid = l + r >> 1;
                if (ask(n - mid + 1, n) == 0) {
                    ans = mid, r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
        } else {
            // k <= n / 2
            for (int l = 2, r = n / 2; l <= r; ) {
                int mid = l + r >> 1;
                if (ask(1, mid) == 1) {
                    ans = mid, r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }

    cout << "! " << ans << "\n";
    fflush(stdout);
}

signed main() {
    int T; cin >> T; fflush(stdout);
    for (; T--; solve());
    // solve();
    return 0;
}
