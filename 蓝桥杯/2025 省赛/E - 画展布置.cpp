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
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int inf = 1e18;

void solve() {
    int n = read();
    int m = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        a[i] = a[i] * a[i];
    }

    sort(a.begin() + 1, a.end());
    int l = 1, r = 1;
    int res = 0;
    int ans = inf;
    while (r + 1 <= m) res += a[r + 1] - a[r], r++;
    for (; r <= n; l++, r++) {
        ans = min(ans, res);

        res -= a[l + 1] - a[l];
        if (r + 1 <= n) res += a[r + 1] - a[r];
    }
    cout << ans << '\n';
}

signed main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // int T; cin >> T;
    int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}