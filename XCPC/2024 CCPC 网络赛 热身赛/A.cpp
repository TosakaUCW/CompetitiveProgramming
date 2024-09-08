#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void solve() {
    int n = read(), m = read();

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> vis(n, vector<int>(m));
    std::array<int, 3> ans;

    auto bfs = [&](int sx, int sy) {
        int cnt = 0;

        std::queue<std::pair<int, int>> q;
        vis[sx][sy] = 1, q.push({sx, sy});
        while (!q.empty()) {
            cnt++;
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if (a[nx][ny] == '.' or vis[nx][ny]) continue;

                q.push({nx, ny}), vis[nx][ny] = 1;
            }
        }

        ans[2] += cnt / 13, cnt %= 13;
        ans[1] += cnt / 8, cnt %= 8;
        ans[0] += cnt / 3;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (a[i][j] == '.') continue;
            bfs(i, j);
        }
    }

    for (auto x : ans) cout << x << ' ';
}

signed main() {
    // sfor (int T = read(); T--; solve());
    solve();
    return 0;
}