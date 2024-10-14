#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();

    vector<int> cnt(m);

    int st = n % m;
    for (int i = 1; i <= m; i++) {
        cnt[i * i % m] += n / m + (i <= st);
    }

    int ans = cnt[0] * (cnt[0] + 1);

    for (int i = 1; i < m; i++) {
        ans += cnt[i] * cnt[m - i];
    }

    if (m % 2 == 0) ans += cnt[m / 2];

    cout << ans / 2;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}