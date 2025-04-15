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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) c[i] = a[i] + b[i];
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    int ans = 0;
    int L = 1;
    for (int R = 1; R <= n; R++) {
        if (c[R] != c[R - 1]) {
            L = R;
        } else {

        }

        ans = max(ans, (sum[R] - sum[L - 1]) * (R - L + 1));
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