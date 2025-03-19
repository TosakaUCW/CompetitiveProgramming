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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int st = read();
    int en = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read();
        int v = read();
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> dis(n + 1, -1);
    dis[en] = 0;

    auto dfs = [&](this auto&& self, int u, int fa) -> void {
        for (int v : g[u]) {
            if (v == fa) continue;
            dis[v] = dis[u] + 1;
            self(v, u);
        }
    };
    dfs(en, -1);
    
    vector<int> p(n);
    ranges::iota(p, 1);
    ranges::sort(p, [&](int a, int b) {
        return dis[a] > dis[b];
    });
    
    if (dis[st] == -1) {
        cout << "-1\n";
    } else {
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
