#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int k = read();

    vector<vector<int>> g(n + 1);
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        p[i] = read();
        g[p[i]].eb(i);
    }

    vector<int> dep(n + 1);

    dep[1] = 1;
    auto dfs = [&](this auto&& dfs, int u) -> void {
        for (int v : g[u]) {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    };
    dfs(1);

    int dmin = inf;
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) {
            dmin = min(dmin, dep[i]);
        }
    }

    vector<int> cnt(dmin + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (dep[i] <= dmin) cnt[dep[i]]++;
    }

    vector<int> cost;
    for (int d = 1; d <= dmin; d++) cost.eb(cnt[d]);
    ranges::sort(cost); 

    const int MAXK = 1000 + 5;
    bitset<MAXK> dp;
    dp[0] = 1; 

    int tot = 0;
    int ans = 0;
    int m = cost.size();

    for (int i = 0; i < m; i++) {
        int w = cost[i];
        tot += w;

        if (w <= 1000) dp |= (dp << w);

        int L = max(0LL, tot - (n - k));
        int R = min(k, tot);
        bool f = 0;
        if (L > R) continue;
        for (int s = L; s <= R; s++) {
            if (dp.test(s)) { f = 1; break; }
        }
        if (f) ans = i + 1;
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}