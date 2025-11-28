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
    int n = read();

    int k = 0;
    while ((k + 1) * (k + 1) <= n) k++;

    vector a(k + 5, vector(k + 5, 0ll));
    int id = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = id++;
        }
    }

    int rem = n - k * k;
    for (int i = 0; i < k and rem; i++) {
        a[i][k] = id++;
        rem--;
    }
    for (int j = 0; j < k and rem; j++) {
        a[k][j] = id++;
        rem--;
    }

    vector<pii> res1, res2;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (a[i][j] and a[i][j + 1]) {
                res1.eb(a[i][j], a[i][j + 1]);
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (a[i][j] and a[i + 1][j]) {
                res2.eb(a[i][j], a[i + 1][j]);
            }
        }
    }

    int ans = min(res1.size(), res2.size());
    cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        auto [u, v] = res1[i];
        cout << u << " " << v << "\n";
    }
    for (int i = 0; i < ans; i++) {
        auto [u, v] = res2[i];
        cout << u << " " << v << "\n";
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}