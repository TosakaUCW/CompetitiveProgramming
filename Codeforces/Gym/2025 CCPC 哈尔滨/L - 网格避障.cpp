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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;
const int dx[] = {0, -1, +1};
const int dy[] = {1, 0, 0};

void solve() {
    int n = read();
    int m = read();
    int k = read();
    vector<int> r(m, -1);
    vector<int> id(m, -1);
    for (int i = 0; i < k; i++) {
        int x = read(), y = read();
        x--, y--;
        r[y] = x;
        id[y] = i;
    }

    int all = 1 << k;
    vector vis(n, vector(m, vector(all, 0)));
    vector dis(n, vector(m, vector(all, inf)));

    struct node { int x, y, s; };
    queue<node> q;
    for (int s = 0; s < all; s++) {
        for (int i = 0; i < n; i++) {
            q.ep(i, 0, s);
            vis[i][0][s] = 1;
            dis[i][0][s] = 0;
        }
    }
    while (!q.empty()) {
        auto [x, y, s] = q.front(); q.pop();

        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 or nx >= n) continue;
            if (ny < 0 or ny >= m) continue;
            if (r[ny] != -1) {
                if (((s >> id[ny]) & 1) and (nx <= r[ny])) continue;
                if (!((s >> id[ny]) & 1) and (nx >= r[ny])) continue;    
            }
            if (vis[nx][ny][s]) continue;

            vis[nx][ny][s] = 1;
            q.ep(nx, ny, s);
            cmin(dis[nx][ny][s], dis[x][y][s] + 1);
        }
    }

    for (int s = 0; s < all; s++) {
        int res = inf;
        for (int i = 0; i < n; i++) cmin(res, dis[i][m - 1][s]);
        if (res == inf) res = -1;
        cout << res << " \n"[s == all - 1];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}