#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max;
using std::min;
using std::swap;
using std::cin;
using std::cout;
using std::string;
using std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
// using namespace std;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

void solve() {
    int n = 2024;

    vector<int> dp(n + 1, inf);
    dp[1] = 0;

    for (int i = 1; i <= n; i++) {
        int x = i + 1;
        if (x <= n) dp[x] = min(dp[x], dp[i] + 1);

        int y = 2 * i;
        if (y <= n) dp[y] = min(dp[y], dp[i] + 10);

        int z = 0;
        for (int j = i; j; j /= 10) {
            z = max(z, j % 10);
        }

        // cout << i << ' ' << z << '\n';
        z += i;
        if (z <= n) dp[z] = min(dp[z], dp[i] + 3);
    }

    cout << dp[n];
}

signed main() {
    // sieve(5000);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}