#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int x = read();
    int y = read();
    int k = read();

    int g = gcd(x, y);
    x /= g, y /= g;

    int n = max(x, y);
    vector dp(n + 1, inf);

    auto dfs = [&](this auto&& dfs, int u) -> int {
        if (dp[u] != inf) return dp[u];
        if (u == 1) return dp[u] = 0;
        if (u <= k) return dp[u] = 1;
        for (int i = 2; i * i <= u and min(i, u / i) <= k; i++) {
            if (u % i != 0) continue;

            if (i <= k) dp[u] = min(dp[u], dfs(u / i) + 1);
            if (u / i <= k) dp[u] = min(dp[u], dfs(i) + 1);
        }
        return dp[u];
    };

    dfs(x), dfs(y);

    if (dp[x] == inf or dp[y] == inf) {
        cout << "-1\n";
    } else {
        cout << dp[x] + dp[y] << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}