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

int A, B, x, y;
vector<pii> a;
vector<tuple<int, int, int, int>> ans;

void solve() {
    A = read(), B = read();
    x = read(), y = read();
    if (x == A and y == B) {
        cout << "0\n";
        return;
    }
    int uA = A; while (uA % 2 == 0 and uA) uA /= 2;
    int uB = B; while (uB % 2 == 0 and uB) uB /= 2;
    if ((uA and x % uA != 0) or (uB and y % uB != 0)) {
        cout << "-1\n";
        return;
    } 

    a.eb(A, 0ll);
    a.eb(0ll, B);
    a.eb(0ll, 0ll);
    a.eb(A, B);

    while (1) {
        for (auto [p, q] : a) {
            if (p == x and q == y) {
                ranges::reverse(ans);
                cout << ans.size() << '\n';
                for (auto [a, b, c, d] : ans) {
                    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                }
                cout << '\n';
                return;
            }
        }

        for (auto [p, q] : a) {
            int nx = 2 * x - p;
            int ny = 2 * y - q;
            if (nx < 0ll or nx > A or ny < 0ll or ny > B) {
                continue;
            }
            if (p == nx and q == ny) continue;
            if (x == nx and y == ny) continue;
            ans.eb(p, q, nx, ny);
            x = nx, y = ny;
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}