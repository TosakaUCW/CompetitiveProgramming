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

const int a[] = {0, 534, 386, 319, 692, 169, 338, 521, 713, 640, 692, 969, 362, 311, 349, 308, 357, 515, 140, 591, 216,
57, 252, 575, 630, 95, 274, 328, 614, 18, 605, 17, 980, 166, 112, 997, 37, 584, 64, 442, 495,
821, 459, 453, 597, 187, 734, 827, 950, 679, 78, 769, 661, 452, 983, 356, 217, 394, 342, 697, 878,
475, 250, 468, 33, 966, 742, 436, 343, 255, 944, 588, 734, 540, 508, 779, 881, 153, 928, 764, 703,
459, 840, 949, 500, 648, 163, 547, 780, 749, 132, 546, 199, 701, 448, 265, 263, 87, 45, 828, 634};

// const int a[] = {0, 6, 6, 6, 6, 6, 6};

// int dp[200][30];

void solve() {
    // vector<int> dp(24, -1);
    int n = 100;
    vector dp(n + 1, vector<int>(24, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][a[i] % 24] = a[i];
        for (int j = 0; j < 24; j++) {
            if (dp[i - 1][j] == -1) continue;
            int x = (j + a[i]) % 24;
            dp[i][x] = max(dp[i][x], dp[i - 1][j] + a[i]);
        }

        cerr << dp[i] << '\n';
    }
    cout << dp[n][0];
}

signed main() {
    // sieve(5000);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}