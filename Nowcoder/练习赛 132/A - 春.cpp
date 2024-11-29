#include <bits/stdc++.h>
// using i64 = long long;
// #define int i64
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

const int inf = 1e9;

void solve() {
    int n = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    std::sort(a.begin() + 1, a.end());

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i];
    }
    for (int i = 3; i <= n; i++) {
        ans += a[i];
    }
    ans = ans / 2;
    // cout << ans << '\n';

    if (n == 1) ans = 0;

    printf("%.2f", ans);
}    

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}