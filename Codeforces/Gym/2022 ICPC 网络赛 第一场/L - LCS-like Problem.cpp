#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s, t = " " + t;

    vector ban(26, vector(26, 0));
    vector<int> vis(26);

    for (int i = m; i >= 1; i--) {
        int ch = t[i] - 'a';
        for (int j = 0; j < 26; j++) {
            if (vis[j]) ban[ch][j] = 1;
        }
        vis[ch] = 1;
    }

    vector<int> dp(26);
    for (int i = 1; i <= n; i++) {
        auto ndp = dp;
        int ch = s[i] - 'a';

        for (int j = 0; j < 26; j++) {
            if (!vis[ch]) {
                ndp[j]++;
            } else if (!ban[j][ch]) {
                ndp[ch] = max(ndp[ch], dp[j] + 1);
            }
        }

        dp = move(ndp);
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}