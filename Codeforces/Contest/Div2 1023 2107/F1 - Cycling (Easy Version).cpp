#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector f(n + 2, vector(n + 2, inf));

    for (int i = 1; i <= n; i++) {
        f[n][i] = a[i] + n - i;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            f[i - 1][j] = min(f[i - 1][j], f[i][j] + a[j] + 1);
            if (i - 1 < j) {
                f[i - 1][i - 1] = min(f[i - 1][i - 1], f[i][j] + a[i - 1]);
            }
        }
    }

    // for (int i = n; i >= 1; i--) {
    //     cerr << f[i] << '\n';
    // }

    int ans = inf;
    ans = *ranges::min_element(f[0]);

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}