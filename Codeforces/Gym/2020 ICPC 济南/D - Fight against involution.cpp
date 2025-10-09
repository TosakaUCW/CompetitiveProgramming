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
    int n = read();

    map<int, int> buk;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = read(), r[i] = read();
    }

    vector<int> p(n);
    ranges::iota(p, 0ll);
    ranges::sort(p, [&](int i, int j) {
        if (r[i] != r[j]) return r[i] < r[j];
        return l[i] > l[j];
        // return r[i] < r[j];
    });

    int t = 0, ans = 0;
    for (int i : p) {
        int L = l[i], R = r[i];
        // cerr << L << ' ' << R << '\n';

        if (!buk.count(R)) {
            t = max(t, L);
            buk[R] = t;
        }
        ans += buk[R];
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}