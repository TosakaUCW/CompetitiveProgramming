#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int a = read(), b = read(), c = read();
    int k = read();
    k = min(k, 1000ll);
    while (k--) {
        int na = (b + c) / 2;
        int nb = (a + c) / 2;
        int nc = (a + b) / 2;
        a = na, b = nb, c = nc;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
}

signed main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T; cin >> T;
    // int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}