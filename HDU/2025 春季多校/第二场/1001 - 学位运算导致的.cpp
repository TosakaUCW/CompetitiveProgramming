#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
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
using pii = std::pair<int, int>;
#define fi first
#define se second
const int P = 1'0000'0000'0000'1029;

void solve() {
    int n = read();
    int q = read();

    vector<ull> a(64, ull(-1));

    while (n--) {
        ull x = read();
        for (int i = 0; i < 64; i++) {
            if (x & (1ull << i)) {
                a[i] &= x;
            }
        }
    }

    ull ans = 0;
    while (q--) {
        ull x = read();
        ull now = 0;
        ull res = ull(-1);
        for (int i = 63; i >= 0; i--) {
            if (x & (1ull << i)) {
                now |= a[i];
            } else {
                res = min(res, now | a[i]);
            }
        }
        ans ^= (min(now, res) % P);
    }    

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}
