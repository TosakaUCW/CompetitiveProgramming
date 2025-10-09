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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int x = read(), y = read(), read();
    int ans = 0;
    while (x >= 3 or y >= 3) {
        int t = min(x, y);
        ans += t * 2;
        x -= t, y -= t;

        // debug(x), debug(y);

        if (y) {
            int t = (y - y / 3) / 2;
            ans += t * 4;
            x += t, y -= t * 2;
        } else {
            int t = (x - x / 3) / 2;
            ans += t;
            y += t, x -= t * 2;
        }
    }

    if (x == 1 and y == 1) ans += 2;
    if (x == 2 and y == 1) ans += 2;
    if (x == 1 and y == 2) ans += 2;
    if (x == 2 and y == 2) ans += 4;

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}