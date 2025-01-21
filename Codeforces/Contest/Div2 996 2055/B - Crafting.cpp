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
    vector<int> a(n);
    vector<int> b(n);

    for (auto &x : a) x = read();
    for (auto &x : b) x = read();


    bool f = 1;
    int t = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < b[i] and f) {
            t -= (b[i] - a[i]);
            f = 0;
            a[i] = b[i] - t;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] + t < b[i]) {
            cout << "No\n";
            return;
        }
    }

    // cerr << a << '\n';
    // cerr << b << '\n';
    cout << "Yes\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}