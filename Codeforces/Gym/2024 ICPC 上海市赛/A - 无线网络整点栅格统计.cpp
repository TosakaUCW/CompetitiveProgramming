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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

void solve() {
    int n = read(), m = read();

    auto calc = [&](int a, int b, int c) -> int {
        if (a < 1 or b < 1) return 0;
        if (c - 1 <= 0) return 0;

        a = min(c, a);
        if (b >= c - 1) {
            return (c - 1 + c - a) * a / 2;
        } else {
            int k = min(c - b, a);
            int res = b * k;
            res += (a - k) * (c - k - 1 + c - a) / 2;
            return res;
        }
    };
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int res = 0;

            res += max(0LL, min(i, j));
            res += max(0LL, min(i, m - j));
            res += max(0LL, min(n - i, j));
            res += max(0LL, min(n - i, m - j));

            res += calc(j, m - j, n - i);
            res += calc(j, m - j, i);
            res += calc(i, n - i, j);
            res += calc(i, n - i, m - j);

            cout << res << " \n"[j == m];
        }
    }
    
    // for (int i = 1; i <= n + 1; i++) {
    //     for (int j = 1; j <= m + 1; j++) {

    //         cout << " \n"[j == m + 1];
    //     }
    // }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}