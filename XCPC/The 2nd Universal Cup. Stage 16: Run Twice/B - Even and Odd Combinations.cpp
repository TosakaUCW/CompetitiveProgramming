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
    int k = read();

    set<int> s;
    bool f = 0;
    for (int i = 0; i < k; i++) {
        int x = read();
        s.insert(x);
        if (x == 1) {
            f = 1;
        }
    }

    if (f) {
        k--;
        s.erase(1);
    } else {
        k++;
        s.insert(1);
    }

    cout << n << ' ' << k << '\n';
    for (int x : s) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // string s; cin >> s;
    // if (s == "first") {
    //     for (int T = read(); T--; solve1());
    //     // solve1();
    // } else {
    //     for (int T = read(); T--; solve2());
    // }
    // solve();
    return 0;
}