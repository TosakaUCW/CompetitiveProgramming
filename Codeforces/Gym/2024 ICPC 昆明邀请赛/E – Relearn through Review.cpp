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
    int n = read(), k = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = std::__gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = std::__gcd(suf[i + 1], a[i]);
    }

    int ans = pre[n];

    for (int i = 1; i <= n; i++) {
        if (pre[i] == pre[i - 1]) continue;

        int g = 0;

        for (int j = i; j <= n; j++) {
            g = std::__gcd(g, a[j] + k);
            ans = max(ans, std::__gcd(pre[i - 1], std::__gcd(g, suf[j + 1])));
        }
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}