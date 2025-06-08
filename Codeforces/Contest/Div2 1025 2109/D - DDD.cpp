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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
	int n = read();
    int m = read();
    int l = read();

    vector<int> a(l);
    for (auto &x : a) x = read();

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = read() - 1;
        int v = read() - 1;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    vector<int> dis(2 * n, inf);
    queue<int> q;
    q.ep(0), dis[0] = 0;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        int u = x / 2, r = x % 2;
        for (int v : adj[u]) {
            int y = 2 * v + !r;
            if (dis[y] != inf) continue;
            dis[y] = dis[x] + 1;
            q.ep(y);
        }
    }
    // cerr << dis << '\n';

    vector<int> f = {0, -1};
    int sum = accumulate(a.begin(), a.end(), 0ll);
    f[sum % 2] = sum;
    for (auto x : a) {
        int t = sum - x;
        f[t % 2] = max(f[t % 2], t);
    }
    // cerr << f << '\n';

    for (int i = 0; i < n; i++) {
        cout << (dis[2 * i] <= f[0] or dis[2 * i + 1] <= f[1]);
    }
    cout << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}