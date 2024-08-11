#include <bits/stdc++.h>
using i64 = long long;
#define int long long

#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), k = read();
    int w = read(), h = read();

    w <<= 1, h <<= 1;
    string s; cin >> s;

    std::map<std::pair<int, int>, int> mp;
    int x = 0, y = 0;
    for (auto c : s) {
        if (c == 'U') y++;
        if (c == 'D') y--;
        if (c == 'L') x--;
        if (c == 'R') x++;
        x = (x + w) % w;
        y = (y + h) % h;
        mp[{x, y}]++;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int nx = (x * (-i) % w + w) % w;
        int ny = (y * (-i) % h + h) % h;
        ans += mp[{nx, ny}];
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}