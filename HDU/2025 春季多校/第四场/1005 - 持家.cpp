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
    double P;
    int n, k;
    cin >> P >> n >> k;

    vector<int> q1, q2;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x == 0) q1.eb(y);
        else q2.eb(-y);
    }

    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());

    int sz1 = q1.size(), sz2 = q2.size();

    vector<double> prod(sz1 + 1), sum(sz2 + 1);

    prod[0] = 1;
    for (int i = 1; i <= sz1; i++) prod[i] = prod[i - 1] * q1[i - 1] / 10.0;
    for (int i = 1; i <= sz2; i++) sum[i] = sum[i - 1] + q2[i - 1];

    double ans = P;
    for (int i = 0; i <= min(k, sz1); i++) {
        int j = k - i;
        if (j > sz2) j = sz2;
        if (j < 0) j = 0;

        ans = min(ans, P * prod[i] + sum[j]);
    }

    if (ans <= 0) ans = 0;

    cout << fixed << setprecision(2) << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
