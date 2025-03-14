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
    string s; cin >> s;
    int n = s.size();
    string k; cin >> k;
    int m = k.size();

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int t = 0;
    if (m > 2) {
        t = 1000;
    } else {
        for (auto ch : k) t = t * 10 + ch - '0';
    }

    while (t != 1) {
        t--;
        auto ndp = dp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] > s[j]) ndp[i] = max(ndp[i], dp[j] + 1);
            }
            for (int j = 0; j < i; j++) {
                if (s[i] > s[j]) ndp[i] = max(ndp[i], ndp[j] + 1);
            }
        }
        dp = move(ndp);
    }

    int ans = 0;
    for (auto &x : dp) ans = max(ans, x);
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
// 