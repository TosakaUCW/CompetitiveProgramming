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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

double eps = 1e-7;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    int cnt = 1;
    vector a(n + 1, vector<int>(m + 1));

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int nj = j - (i - 1);
            if (nj < 1) break;
            a[i][nj] = cnt++;
        }
    }
    for (int k = 2; k <= n; k++) {
        int j = m;
        for (int i = k; i <= n; i++) {
            if (j < 1) break;
            a[i][j] = cnt++;
            j--;
        }
    }

    vector<int> vis(cnt * 2);

    bool f = 1;
    for (int i = 1; i + 1 <= n; i++) {
        for (int j = 1; j + 1 <= m; j++) {
            if (vis[a[i][j] + a[i][j + 1]]) {
                f = 0;
            }
            vis[a[i][j] + a[i][j + 1]] = 1;
            if (vis[a[i][j] + a[i + 1][j]]) {
                f = 0;
            }
            vis[a[i][j] + a[i + 1][j]] = 1;
        }
    }

    if (!f) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " \n"[j == m];
        }
    }
}

/*
1-9
146
725
983
*/

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
