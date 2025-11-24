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
const double eps = 1e-10;

void solve() {
    double x0 = read(), y0 = read();
    double vx = read(), vy = read();

    double y1 = read(), y2 = read();
    double vy1 = read(), vy2 = read();

    double x1 = read(), x2 = read();
    double vx1 = read(), vx2 = read();

    double end = (y2 - y1) / (vy1 + vy2);

    double x = x0;
    double y = y1 + end * vy1;

    vx1 = -vx1;
    double cur = 0;

    if (vx1 == 0 and vx2 == 0) {
        double p = 2.0 * (x2 - x1) / abs(vx);
        cur += floor(end / p) * p;
    }

    while (cur < end - eps) {
        double t = end - cur;
        if (vx < 0 and vx < vx1) cmin(t, (x1 - x) / (vx - vx1));
        if (vx > 0 and vx > vx2) cmin(t, (x2 - x) / (vx - vx2));

        x1 += t * vx1;
        x2 += t * vx2;
        x += t * vx;
        vx = -vx;
        cur += t;
    }


    cout << fixed << setprecision(12);
    cout << x << " " << y << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}