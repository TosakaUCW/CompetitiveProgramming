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

void solve1() {
    int n = read();
    vector<int> a(n);
    for (auto &x : a) x = read();
    for (auto x : a) {
        if (x != 1 and x != n) continue;
        cout << (x == 1) << endl;
        return;
    }
}

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x = read(); return x;
}

void solve2() {
    int n = read(), x = read();

    int lp, rp;
    for (int l = 1, r = n; l <= r; ) {
        int mid = l + r >> 1;
        if (ask(1, mid) == n - 1) {
            rp = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    for (int l = 1, r = n; l <= r; ) {
        int mid = l + r >> 1;
        if (ask(mid, n) == n - 1) {
            lp = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    int ans = x ? rp : lp;
    cout << "! " << ans << endl;
}

signed main() {
    // for (int T = read(); T--; solve());
    string s; cin >> s;
    if (s == "first") {
        for (int T = read(); T--; solve1());
        // solve1();
    } else {
        for (int T = read(); T--; solve2());
    }
    // solve();
    return 0;
}