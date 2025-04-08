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
const int inf = 1e8;

double distSegment(double x, double y, double d) {
    if (y > d) {
        double dy = y - d;
        return sqrt(x * x + dy * dy);
    } else {
        return fabs(x);
    }
}

void solve() {
    int d, r, x, y;
    cin >> d >> r >> x >> y;
    x = abs(x), y = abs(y);

    double segDist = distSegment(x, y, d);
    double ans = fabs(segDist - r);
    int res = llround(ans);

    cout << res << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}