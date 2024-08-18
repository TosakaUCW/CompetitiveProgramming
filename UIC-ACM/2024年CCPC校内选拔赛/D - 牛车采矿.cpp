#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    using pii = std::pair<double, int>;
    vector<pii> a(n + 1);

    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;

        auto &[dis, idx] = a[i];
        idx = i;

        if (x < x1) dis += 1.0 * (x1 - x) * (x1 - x);
        if (x2 < x) dis += 1.0 * (x2 - x) * (x2 - x);
        if (y < y1) dis += 1.0 * (y1 - y) * (y1 - y);
        if (y2 < y) dis += 1.0 * (y2 - y) * (y2 - y);

        printf("%.9lf ", sqrt(dis));
    }

    std::sort(a.begin() + 1, a.end());
    cout << '\n' << a[1].second << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("cow1.in", "r", stdin);
    freopen("cow1.ans", "w", stdout);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}