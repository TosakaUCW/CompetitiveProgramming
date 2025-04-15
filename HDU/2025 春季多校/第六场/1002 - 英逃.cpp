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
const int N = 1e5 + 5;
int st[N][25];
int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve() {
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int j = 1; j <= 21; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    // for (int i = 2; i <= n; i++) {
    //     cout << abs(a[i] - a[i - 1]) << " \n"[i == n];
    // }

    vector<int> sum(n + 5);
    vector<int> c(n + 5);
    for (int i = 2; i <= n; i++) c[i] = abs(a[i] - a[i - 1]);
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + c[i];

    auto judge = [&](int len) -> bool {
        // a[l, r]
        // c[l + 1, r] -> 0
        // c[r + 1] -> a[r + 1] - mx

        for (int l = 1, r = len; r <= n; l++, r++) {
            int mx = query(l, r);

            int t = sum[n];
            t -= sum[r] - sum[l];
            if (r + 1 <= n) t += abs(a[r + 1] - mx) - c[r + 1];
            if (l >= 2) t += abs(mx - a[l - 1]) - c[l];

            if (t <= x) return 1;
        }
        return 0;
    };

    int ans = n;
    for (int L = 2, R = n; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) {
            ans = mid; R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    if (sum[n] <= x) ans = 0;

    cout << ans << '\n';

    for (int j = 0; j < 25; j++) {
        for (int i = 1; i <= n; i++) {
            st[i][j] = 0;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}