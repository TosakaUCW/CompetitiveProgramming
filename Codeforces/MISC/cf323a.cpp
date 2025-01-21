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

    vector a(n + 1, vector<int>(n + 1, 0));
    if (n & 1) {
        puts("-1");
        return;
    }

    for (int p = 1; p <= n; p++)
        for (int i = p; i <= n - p + 1; i++)
            for (int j = p; j <= n - p + 1; j++) {
                if (i == p or i == n - p + 1) a[i][j] = p & 1;
                else if (j == p or j == n - p + 1) a[i][j] = p & 1;
                else a[i][j] = (p & 1) ^ 1;
            }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (a[i][j] ? 'w' : 'b');
                a[i][j] ^= 1;
            }
            cout << '\n';
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
