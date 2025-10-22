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

const int N = 5e4 + 5;

void solve() {
    string s, t;
    cin >> s >> t;

    int a[4] {};
    int b[4] {};

    int id = 0;
    for (auto ch : s) {
        if (ch == '.') id++;
        else a[id] = a[id] * 10 + ch - 48;
    }
    id = 0;
    for (auto ch : t) {
        if (ch == '.') id++;
        else b[id] = b[id] * 10 + ch - 48;
    }

    int f = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] > b[i]) { f = 1; break; }
        else if (a[i] < b[i]) { f = -1; break; }
    }

    if (f == 1) cout << "A\n";
    if (f == -1) cout << "B\n";
    if (f == 0) cout << "Equal\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}