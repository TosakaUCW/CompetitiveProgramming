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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    vector<int> a(n);
    for (auto &x : a) x = read();

    auto f = [&](int x, int y) -> int {
        return x % y + y % x;
    };

    int mx = a[0];
    int res = 0;
    cout << "0 ";
    for (int i = 1; i < n; i++) {
        if (a[i] >= mx * 2) {
            res = 0;
            mx = a[i];
            for (int j = 0; j < i; j++) {
                res = max(res, f(mx, a[j]));
            }
        } else if (a[i] > mx) {
            res = a[i];
            mx = a[i];
        } else {
            res = max(res, f(mx, a[i]));
        }
        cout << res << " \n"[i == n - 1];
    }    
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}