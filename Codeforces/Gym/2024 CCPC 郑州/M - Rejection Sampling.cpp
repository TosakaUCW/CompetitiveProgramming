#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
// const int inf = 1e18;

using ld = long double;

void solve() {
    int n = read();
    int k = read();
    vector<double> a(n);
    for (auto &x : a) x = read();

    auto calc = [&](ld h) {
        ld res = 0;
        for (auto x : a) {
            res += h * x / (h * x + 1);
        }
        return res;
    };

    ld l = 0, r = 1e5;
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) / 2.0;
        if(calc(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    ld h = r;
    for (auto x : a) {
        printf("%.15Lf\n", h * x / (h * x + 1));
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}