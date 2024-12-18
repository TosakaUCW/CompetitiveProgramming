#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
int ceil(int x, int y) { return x / y + (x % y != 0); }
void solve() {
    int n = read(), k = read();

    int rem = n, x = 1;
    int rnd = 0;
    while (rem > 1) {
        int delta = ceil(rem, k);
        int w = max(1LL, ceil(rem % k, delta));
        if (rem <= k) w = rem - 1;
        rem -= w * delta;
        rnd += w;
    }
    while (rnd) {
        int delta = ceil(x, k - 1);
        int up = delta * (k - 1);
        int w = max(1LL, ceil(up - x, delta));
        if (w > rnd) w = rnd;
        rnd -= w;
        x += w * delta;
    }

    cout << x << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
