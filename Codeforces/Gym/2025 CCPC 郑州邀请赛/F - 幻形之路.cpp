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
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    int n = read();
    int m = read();
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    queue<pii> q;
    
    auto go1 = [&](int sx, int sy) {
        queue<pii> q;
        vector<pii> res;
        q.ep(sx, sy), res.eb(sx, sy);
        vector vis(n, vector(m, 0));
        vis[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            // debug(x); debug(y);
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if (g[nx][ny] == '#') continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.ep(nx, ny);
                res.eb(nx, ny);
            }
        }
        return res;
    };
    auto go2 = [&](auto a) {
        vector dis(n, vector(m, inf));
        for (auto [x, y] : a) dis[x][y] = 0, q.ep(x, y);
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if (dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.ep(nx, ny);
                }
            }
        }
        return dis;
    };

    auto dis1 = go2(go1(0, 0));
    auto dis2 = go2(go1(n - 1, m - 1));

    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = min(ans, dis1[i][j] + dis2[i][j] - 1);
        }
    }
    ans = max(ans, 0ll);
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}