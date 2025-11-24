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

/*
6 4 3 13
2 4 3 9
2 2 3 7
2 2 1 5
2 2 1 5
*/

void solve() {
    int n = read();
    int s = read();
    s--;

    vector<pii> P(n), Q(n);
    for (int i = 0; i < n; i++) {
        auto &[x1, y1] = P[i];
        auto &[x2, y2] = Q[i];
        cin >> x1 >> y1 >> x2 >> y2;
    }

    int sx1 = 0, sx2 = 0;
    int sy1 = 0, sy2 = 0;
    for (int i = 0; i < n; i++) {
        auto &[x1, y1] = P[i];
        auto &[x2, y2] = Q[i];
        sx1 += x1;
        sx2 += x2;
        sy1 += y1;
        sy2 += y2;
    }

    auto &[x0, y0] = P[s];
    for (int t = 0; t < n; t++) {
        auto &[x1, y1] = Q[t];
        if (sx1 + 2 * (x1 - x0) != sx2) continue;
        if (sy1 + 2 * (y1 - y0) != sy2) continue;
        cout << t + 1 << '\n';
        break;
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}