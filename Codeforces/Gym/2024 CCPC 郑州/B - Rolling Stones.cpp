#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    vector<int> len(n + 1);
    vector grid(n + 1, vector(2 * n, 0));
    vector vis(n + 1, vector(2 * n, 0));
    for (int i = 1; i <= n; i++) {
        len[i] = 2 * i - 1;
        for (int j = 1; j <= len[i]; j++) {
            grid[i][j] = read() - 1;
        }
    }

    int tarx = read();
    int tary = read();


    vector mp(n + 1, vector(2 * n, 0));
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int k = 3, j = 1; j <= len[i]; j++, k = (k - 1 + 4) % 4) {
                mp[i][j] = k;
            }
        } else {
            for (int k = 0, j = 1; j <= len[i]; j++, k = (k + 1) % 4) {
                mp[i][j] = k;
            }
        }

        // cerr << mp[i] << '\n';
    }

    const int dx[] = {0, 0, +1, -1};
    const int dy[] = {1, -1, +1, -1};

    queue<pii> q;
    q.ep(1, 1); vis[1][1] = 1;
    vector dis(n + 1, vector(2 * n, 0));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // cerr << x << ' ' << y << '\n';

        if (x == tarx and y == tary) {
            cout << dis[tarx][tary] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (i == 2 and y % 2 != 1) continue;
            if (i == 3 and y % 2 != 0) continue;

            if (1 <= nx and nx <= n and
                1 <= ny and ny <= len[nx] and
                grid[nx][ny] == mp[nx][ny] and 
                !vis[nx][ny]) {

                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
                q.ep(nx, ny);
            }
        }
    }

    cout << "-1" << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}