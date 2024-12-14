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
const int N = 3e2 + 5;

int a[N][N];
int s[N][N];

void solve() {
    int n = read();
    int m = read();

    // vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
        }
    }

    // vector s(n + 1, vector<int>(m + 1));    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        // if (x2 < x1 or y2 < y1) return 0LL;
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    };

    int ans = -inf;

    // cout << get(2, 2, 1, 1) << '\n';

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int len = 2; x1 + len - 1 <= n and y1 + len - 1 <= m; len++) {
                int x2 = x1 + len - 1;
                int y2 = y1 + len - 1;
                int res = get(x1, y1, x2, y2) - get(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                ans = max(ans, res);
            }
        }
    }

    cout << ans;
}

signed main() {
    // sieve(5000);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}