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
const int inf = 1e18;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector a(2, vector(n + 1, 0ll));

    for (int j = 1; j <= n; j++) {
        a[0][j] = s[j - 1] == '#';
        a[1][j] = t[j - 1] == '#';
    }
    // int n = s[0].size();

    int ans = 0;
    int las[2] = {0, 0};

    for (int j = 1; j <= n; j++) {
        if (a[0][j] + a[1][j] == 0) continue;

        if (a[0][j]) las[0] = j;
        if (a[1][j]) las[1] = j;

        for (j = j + 1; j <= n; j++) {
            if (a[0][j] + a[1][j] == 0) continue;

            int res = inf;
            
            if (a[0][j]) {
                res = min({
                    res,
                    j - las[0] - 1,
                    j - las[1]
                });
            }

            if (a[1][j]) {
                res = min({
                    res,
                    j - las[1] - 1,
                    j - las[0]
                });
            }

            ans += res;

            if (!a[0][j] and res == j - las[0]) {
                las[0] = j;
            }
            if (!a[1][j] and res == j - las[1]) {
                las[1] = j;
            }

            if (a[0][j]) las[0] = j;
            if (a[1][j]) las[1] = j;

            // cout << j << ' ' << res << '\n';
        }
        break;
    }

    cout << ans << '\n';
}

signed main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // int T; cin >> T;
    int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}