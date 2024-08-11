#include <bits/stdc++.h>
#define int long long
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();

    vector<vector<int>> a(2);

    for (int i = 1; i <= n; i++) {
        int x = read();
        a[x % 2].pb(x);
    }

    std::sort(a[0].begin(), a[0].end());
    std::sort(a[1].begin(), a[1].end());

    if (a[0].empty() || a[1].empty()) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 0;

    for (int i = 0; i < a[0].size(); i++) {
        int x = a[0][i];
        if (a[1].back() > x) {
            ans++;
            a[1].back() += x;
        }
        else {
            ans += a[0].size() + 1 - i;
            break;
        }
    }
    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}