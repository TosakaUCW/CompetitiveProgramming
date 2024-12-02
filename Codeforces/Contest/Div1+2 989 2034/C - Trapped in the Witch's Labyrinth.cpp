#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int m = read();

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector bad(n, vector<int>(m));

    std::queue<pii> q;

    for (int i = 0; i < n; i++) {
        if (s[i][0] == 'L') {
            bad[i][0] = 1;
            q.ep(i, 0);
        }
        if (s[i][m - 1] == 'R') {
            bad[i][m - 1] = 1;
            q.ep(i, m - 1);
        }
    }
    for (int i = 0; i < m; i++) {
        if (s[0][i] == 'U') {
            bad[0][i] = 1;
            q.ep(0, i);
        }
        if (s[n - 1][i] == 'D') {
            bad[n - 1][i] = 1;
            q.ep(n - 1, i);
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x > 0 and !bad[x - 1][y] and s[x - 1][y] == 'D') {
            bad[x - 1][y] = 1;
            q.ep(x - 1, y);
        }
        if (x < n - 1 and !bad[x + 1][y] and s[x + 1][y] == 'U') {
            bad[x + 1][y] = 1;
            q.ep(x + 1, y);
        }
        if (y > 0 and !bad[x][y - 1] and s[x][y - 1] == 'R') {
            bad[x][y - 1] = 1;
            q.ep(x, y - 1);
        }
        if (y < m - 1 and !bad[x][y + 1] and s[x][y + 1] == 'L') {
            bad[x][y + 1] = 1;
            q.ep(x, y + 1);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!bad[i][j] and s[i][j] != '?') ans++;
            else if (!bad[i][j]) {
                bool f = 1;
                if (i > 0) f &= bad[i - 1][j];
                if (i < n - 1) f &= bad[i + 1][j];
                if (j > 0) f &= bad[i][j - 1];
                if (j < m - 1) f &= bad[i][j + 1];
                if (!f) ans++;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}