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
const int INF = 1e18;

void solve() {
    int K = 0;
    int n = read();
    int m = read();

    string s; cin >> s;

    vector a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = read();
        }
    }

    vector<pii> path;
    path.eb(0, 0);
    int x = 0, y = 0;
    for (auto ch : s) {
        if (ch == 'R') y++;
        else x++;
        path.eb(x, y);
    }
    for (int k = 0; k < path.size(); k++) {
        auto [x, y] = path[k];
        if (k < path.size() - 1) {
            auto [nx, ny] = path[k + 1];
            if (nx > x) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += a[x][j];
                }
                a[x][y] = -(sum - a[x][y]);
            } else {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += a[i][y];
                }
                a[x][y] = -(sum - a[x][y]);
            }
        } else {
            int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += a[i][y];
                }
                a[x][y] = -(sum - a[x][y]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
    }

    // cerr << b << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
