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

    vector<int> a(n + 1);

    vector<vector<int>> buk(n + 1);
    int cnt = 0;
    std::map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        a[i] = read();

        if (!mp[i - a[i]]) mp[i - a[i]] = ++cnt;
        buk[mp[i - a[i]]].pb(a[i]);
    }

    i64 ans = 0;
    for (auto x : buk) {
        std::sort(x.rbegin(), x.rend());
        int m = x.size();
        for (int i = 0; i + 1 < m; i += 2) {
            if (x[i] + x[i + 1] > 0) {
                ans += x[i] + x[i + 1];
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}