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

ostream &operator<<(ostream &os, i128 n) {
    if (n == 0) return os << 0;
    string s; while (n > 0) s += char('0' + n % 10), n /= 10;
    reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    int n = read();
    int k = read();
    int a = read();
    int b = read();

    auto judge = [&](i128 M) {
        i128 res = 0;
        for (int d = 1; d <= n - 1; d++) {
            i128 t = min<i128>(n - d, (M - 2 * b * d - a * d * d) / (2 * a * d));
            // assert(t >= 0);
            if (t < 0) break;
            res += t;
            if (res >= k) break;
        }
        return res;
    };

    i128 ans = 0;
    for (i128 l = 0, r = 1e30; l <= r; ) {
        i128 mid = (l + r) / 2;
        if (judge(mid) >= k) {
            ans = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    i128 g = __gcd(ans, i128(a));

    i128 p = ans / g;
    i128 q = i128(a) / g;
    cout << p << " " << q << "\n";
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}