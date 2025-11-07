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

    const int coef = 1e6;

    vector<int> a(n);
    for (int &x : a) x = read() * coef;

    int sum = accumulate(a.begin(), a.end(), 0ll);
    int need;

    if (sum == 100 * coef) {
        need = 0;
    } else if (sum > 100 * coef) {
        need = sum - 100 * coef;
        for (int &x : a) {
            if (x <= 0) continue;

            int t = min(need, coef / 2);
            x -= t, need -= t;
        }
    } else {
        need = 100 * coef - sum;
        for (int &x : a) {
            if (x >= 100 * coef) continue;

            int t = min(need, coef / 2 - 1);
            x += t, need -= t;
        }
    }

    if (need) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}