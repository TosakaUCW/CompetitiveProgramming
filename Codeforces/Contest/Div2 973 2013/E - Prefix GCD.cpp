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

void solve() {
    int n = read();
    int g = 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        g = std::gcd(g, a[i]);
    }

    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        int mn = 1e9;
        for (int j = 1; j <= n; j++) {
            mn = min(mn, std::gcd(cur, a[j]));
        }

        cur = mn;
        ans += cur;

        if (g == cur) {
            ans += (n - i) * g;
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}