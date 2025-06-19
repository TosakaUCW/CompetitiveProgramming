#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int w = read(), h = read();
    int a = read(), b = read();

    int x1 = read(), y1 = read();
    int x2 = read(), y2 = read();

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    bool f = 0;
    if (dx % a == 0) {
        if (dx != 0) f = true;
        else f = (dy % b == 0);
    }
    if (!f and dy % b == 0) {
        if (dy != 0) f = true;
        else f = (dx % a == 0);
    }

    cout << (f ? "Yes" : "No") << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}