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
using pii = std::pair<int, int>;
#define fi first
#define se second
const int inf = 1e18;
struct Node {
    int d, x, y, z;
    bool friend operator< (Node a, Node b) {
        return a.d > b.d;
    }
};

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    vector a(n, vector(m, 0));
    vector b(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    auto dijkstra = [&]() {
        vector dis(n, vector(m, vector(4, inf)));
        vector vis(n, vector(m, vector(4, 0)));

        dis[0][0][0] = 0;
        std::priority_queue<Node> q; q.ep(0, 0, 0, 0);
        while (!q.empty()) {
            auto [d, x, y, z] = q.top(); q.pop();
            if (vis[x][y][z]) continue; vis[x][y][z] = 1;

            // cerr << x << ' ' << y << ' ' << z << "\n";

            for (int i = 0; i < 4; i++) {
                int nz = (z + i) % 4;
                int nx = x + dx[nz];
                int ny = y + dy[nz];

                if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;

                int nd = d + a[x][y];
                if (z != nz) nd += b[x][y];

                if (dis[nx][ny][nz] > nd) {
                    dis[nx][ny][nz] = nd;
                    q.ep(nd, nx, ny, nz);
                }
            }
        }

        // cerr << "--------\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cerr << dis[i][j][0] << " \n"[j == m - 1];
        //     }
        // }
        // cerr << "--------\n";

        int res = inf;
        res = min({
            dis[n - 1][m - 1][0] + b[n - 1][m - 1],
            dis[n - 1][m - 1][1]
        });
        return res + a[n - 1][m - 1];
    };
    cout << dijkstra() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
