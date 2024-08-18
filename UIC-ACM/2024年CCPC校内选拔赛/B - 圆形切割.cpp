#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int now = 0;
    vector<int> vis(360);
    int n = read();
    vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        now = (now + read()) % 360;
        vis[now] = 1;
    }

    int las = 0, ans = 0;
    for (int i = 1; i < 360; i++) {
        if (vis[i]) {
            ans = std::max(ans, i - las);
            las = i;
        }
    }
    ans = std::max(ans, 360 - las);
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}