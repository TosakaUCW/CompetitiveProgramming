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
struct Node {
    int id, a, b;
    bool friend operator< (Node a, Node b) {
        return a.b > b.b;
    }
};

void solve() {
    int n = read();
    int m = read();

    struct edge { int v, a, b; };
    vector<vector<edge>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        int a = read();
        int b = read();

        g[u].eb(v, a, b);
        // g[v].eb(u, a, b);
    }

    #define M (60005)
    vector dis(n + 1, vector(M, inf));

    dis[1][0] = 0;
    for (int a = 0; a < M; a++) {
        for (int u = 1; u <= n; u++) {
            for (auto [v, da, db] : g[u]) {
                int na = a + da;
                int nb = dis[u][a] + db;
                if (na >= M) continue;
                dis[v][na] = min(dis[v][na], dis[u][a] + db);
            }
        }
    }
    // debug(dis);
    const auto &res = dis[n];

    int p = 1;
    for (int i = 1; i < M; i++) {
        if (res[i] == inf) continue;
        if (res[i] * i < res[p] * p) p = i;
    }
    cout << p << ' ' << res[p] << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}