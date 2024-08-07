#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve() {
    int n = read();

    string s; cin >> s;

    int x = 0, y = 0, opt = 0;

    using pii = std::pair<int, int>;
    std::map<pii, bool> mp;
    bool flag = 0;

    for (int i = 0; i < n; i++) {

        int nx = x + dx[opt], ny = y + dy[opt];

        if (s[i] == 'L') {
            opt = (opt + 1) % 4;
        }
        if (s[i] == 'R') {
            opt = (opt - 1 + 4) % 4;
        }

        if (mp.count({nx, ny})) {
            puts("-1");
            return;
        }
        mp[{nx, ny}] = 1;
        x = nx, y = ny;
    }

    int nx = x + dx[opt], ny = y + dy[opt];
    if (x == 0 and y == 0 and nx == 1 and ny == 0) puts("1");
    else puts("0");

}

/*
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}