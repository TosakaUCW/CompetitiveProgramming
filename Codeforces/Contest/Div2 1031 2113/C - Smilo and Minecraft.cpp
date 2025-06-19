#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read(), m = read(), k = read();

    vector<string> g(n);
    for (auto &s : g) cin >> s;

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    int tot = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
            if (g[i][j] == 'g') {
                ++sum[i + 1][j + 1];
                ++tot;
            }
        }

    auto qry = [&](int r1, int c1, int r2, int c2) -> int {
        if (r1 > r2 or c1 > c2) return 0;
        return sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] + sum[r1][c1];
    };

    int rad = k - 1;
    int mn = INT_MAX;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == '.') {
                int r1 = max(0, i - rad);
                int c1 = max(0, j - rad);
                int r2 = min(n - 1, i + rad);
                int c2 = min(m - 1, j + rad);
                int bad = qry(r1, c1, r2, c2);
                mn = min(mn, bad);
            }

    int ans = tot - mn;

    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; ) solve();
    return 0;
}
