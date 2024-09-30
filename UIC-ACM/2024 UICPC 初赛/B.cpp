#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::cin, std::cout, std::string, std::vector;
using std::max, std::min, std::swap;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }

    cout << ans;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}