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

vector<vector<int>> operator * (auto A, auto B) {
    int n = A.size();
    vector C(n, vector(n, 0ll));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }   
    return C;
}

void solve() {
    int n = read(), m = read();
    int k = read(), r = read();

    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        a[i] = read(), c[i] = read();
    }

    int all = 1 << n;
    vector bas(all, vector(all, 0ll));
    for (int s = 0; s < all; s++) {
        for (int t = 0; t < all; t++) {

            int ta = 0, tc = 0;

            for (int i = 0; i < n; i++) {
                if (t >> i & 1) {
                    tc += c[i] + k * (s >> i & 1);
                    ta += a[i];
                }
            }

            if (tc > m) continue;
            bas[s][t] = ta;
        }
    }

    vector f(all, vector(all, 0ll));
    for (; r; r /= 2) {
        if (r & 1) f = f * bas;
        bas = bas * bas;
    }

    int ans = 0;
    for (int i = 0; i < all; i++) {
        cmax(ans, ranges::max(f[i]));
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}