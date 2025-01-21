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
    int k = read() * 2;
    int l = read() * 2;

    vector a(n, 0);
    for (auto &x : a) x = read() * 2;

    int tim = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];

        if (i == 0) {
            tim += x - 0;
            pos += k;
            continue;
        }

        // lasCar in pos - k
        // now we in pos
        // nowCar in [x - tim, x + tim]
        if (pos < x - tim) {
            int d = (x - tim) - pos;

            tim += d / 2;
            pos += d / 2 + k;
        } else if (pos > x + tim) {
            pos = max(pos, x + tim + k);
        } else {
            pos += k;
        }

    }

    tim += max(0ll, l - pos);
    cout << tim << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
