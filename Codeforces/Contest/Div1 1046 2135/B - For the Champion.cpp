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
const int K = 1e9;

int ask(char dir, int k) {
    cout << "? " << dir << " " << k << endl;
    int res; cin >> res; return res;
}

void solve() {
    int n = read();
    vector<pii> a(n);
    for (auto &[x, y] : a) cin >> x >> y;

    int s = -inf, d = -inf;
    for (auto [x, y] : a) {
        s = max(s, x + y);
        d = max(d, x - y);
    }

    int B = 1e9;
    ask('R', K); ask('R', K); ask('U', K);
    int u1 = ask('U', K);

    ask('D', K); ask('D', K); ask('D', K);
    int u2 = ask('D', K);

    int u = u1 - 4 * B + s;
    int v = u2 - 4 * B + d;

    int x = (u + v) / 2;
    int y = (u - v) / 2;

    cout << "! " << x << " " << y << endl;
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}