#include <bits/stdc++.h>
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
const int P = 1e9 + 7;
void add(int &x, int y) { x += y; if (x >= P) x -= P; }
char a[105][105];
int tr[128][8005];
int dp[105][105][8005];

void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    auto calc = [&](int x, int y, int z) {
        return (x * k + y) * k + z;
    };

    for (int sum = 0; sum < k; sum++) {
        for (int mul = 0; mul < k; mul++) {
            for (int cur = 0; cur < k; cur++) {
                for (int dig = '0'; dig <= '9'; dig++) {
                    tr[dig][calc(sum, mul, cur)] = calc(sum, mul, (cur * 10 + dig - '0') % k);
                    tr['+'][calc(sum, mul, cur)] = calc((sum + mul * cur) % k, 1, 0);
                    tr['-'][calc(sum, mul, cur)] = calc((sum + mul * cur) % k, k - 1, 0);
                    tr['*'][calc(sum, mul, cur)] = calc(sum, mul * cur % k, 0);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    a[n][m + 1] = '+';

    int S = k * k * k;
    dp[1][1][calc(0, 1, (a[1][1] - '0') % k)] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1 + (i == 1); j <= m + (i == n); j++) {
            char ch = a[i][j];
            for (int s = 0; s < S; s++) {
                if (isdigit(ch) or isdigit(a[i - 1][j]))
                    add(dp[i][j][tr[ch][s]], dp[i - 1][j][s]);
                if (isdigit(ch) or isdigit(a[i][j - 1]))
                    add(dp[i][j][tr[ch][s]], dp[i][j - 1][s]);
            }
        }
    }

    cout << dp[n][m + 1][calc(0, 1, 0)] << '\n';

    memset(dp, 0, sizeof dp);
}

signed main() {
    int T; scanf("%d", &T);
    for (; T--; solve());
    // solve();
    return 0;
}