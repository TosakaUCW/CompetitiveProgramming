#include <bits/stdc++.h>
using i64 = long long;
// #define int long long
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}


void solve() {
    i64 n = read(), m = read(), k = read();

    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();

    i64 cnt = 0;
    for (int i = 1; i <= n; i++) cnt += a[i] - 1;
    cnt = min(cnt, m - 1);
    i64 x = cnt + 1;
    if (x <= k) puts("YES");
    else puts("NO");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}