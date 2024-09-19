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
    int n = read(), k = read();

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = read();
    std::sort(a.rbegin(), a.rend());

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        int t = min(k, a[i - 1] - a[i]);
        k -= t, a[i] += t;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ans += a[i];
        else ans -= a[i];
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}