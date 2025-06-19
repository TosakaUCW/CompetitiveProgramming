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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    string s; cin >> s;
    s = " " + s;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();

        g[u].eb(v);
        g[v].eb(u);
    }

    vector cnt(3, vector(n + 1, 0));
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (s[v] == 'C') cnt[0][u]++;
            if (s[v] == 'S') cnt[1][u]++;
            if (s[v] == 'P') cnt[2][u]++;
        }
    }

    int ans = 0;
    string t = "*SCCPC";

    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        if (s[u] == 'C') {
            int x = 0;
            int y = 0;
            for (int v : g[u]) {
                if (s[v] == 'C') x += cnt[1][v];
                if (s[v] == 'P') y += cnt[0][v] - 1;
            }
            // y--;
            // if (x * y > 0) {
            //     debug(x);
            //     debug(y);
            // }
            ans += x * y;
        }
        
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
        }
    };

    dfs(1, 0);

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}