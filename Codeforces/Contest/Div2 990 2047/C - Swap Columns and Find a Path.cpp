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

const int inf = 1e18;

void solve() {
    int n = read();
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
    }

    vector f(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        f[i][i] = max(a[i], b[i]);
        for (int j = i + 1; j <= n; j++) {
            f[i][j] = f[i][j - 1] + max(a[j], b[j]);
        }
    }

    int ans = -inf;

    for (int i = 1; i <= n; i++) {
        int res = a[i] + b[i];
        res += f[1][i - 1] + f[i + 1][n];
        ans = max(ans, res);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}