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

void solve() {
    int n = read();

    vector<int> a;
    // a.eb(1);

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.eb(i);

            if (n / i != i) {
                a.eb(n / i);
            }
        }
    }

    std::sort(a.begin(), a.end());

    int ans = 0;
    int m = a.size();
    for (int i = 1; i < m; i++) {
        // cout << "a: " << a[i] << '\n';
        ans += n / a[i - 1] * (a[i] - a[i - 1]);
    }

    ans += n / a[m - 1] * (n - a[m - 1] + 1);

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}