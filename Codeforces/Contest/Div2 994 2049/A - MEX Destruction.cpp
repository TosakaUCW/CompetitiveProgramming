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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    int ans = 2;
    int l = 0;
    while (l + 1 <= n and a[l + 1] == 0) l++;
    int r = n + 1;
    while (r - 1 >= 1 and a[r - 1] == 0) r--;

    bool f = 1;
    for (int i = l + 1; i < r; i++) {
        if (a[i] == 0) {
            f = 0;
            break;
        }
    }

    if (f) ans = 1;
    else ans = 2;

    if (l == n and r == 1) ans = 0;

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
