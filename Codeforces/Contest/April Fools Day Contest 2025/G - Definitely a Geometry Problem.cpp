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
using pii = std::pair<int, int>;
#define fi first
#define se second

const double pi = acos(-1.0);

void solve() {
    int n = read(), k = read();

    vector<pii> a(n);

    for (auto &[x, y] : a) x = read(), y = read();

    ranges::sort(a);

    double d = 8e18;
    for (int i = 0; i + k - 1 < n; i++) {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[i + k - 1];
        double t = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        d = min(d, t);
    }

    double ans = d * pi / 4.0;
    cout << fixed << setprecision(15) << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
