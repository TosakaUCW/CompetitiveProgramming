#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::cerr;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();

    using pii = std::pair<int, int>;

    vector<pii> a(n + 1), b(m + 1), c(m + 1);
    vector<int> buk;

    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        a[i] = {x, y};
        buk.pb(x), buk.pb(y);
    }
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        b[i] = {x, y};
        c[i] = {y, y + 2 * (y - x)};
        buk.pb(x), buk.pb(y);
        buk.pb(y + 2 * (y - x));
    }
    buk.pb(0);

    std::sort(buk.begin(), buk.end());
    buk.erase(std::unique(buk.begin(), buk.end()), buk.end());

    #define fi first
    #define se second

    for (int i = 1; i <= n; i++) {
        a[i].fi = std::lower_bound(buk.begin(), buk.end(), a[i].fi) - buk.begin() + 1;
        a[i].se = std::lower_bound(buk.begin(), buk.end(), a[i].se) - buk.begin() + 1;
        // cerr << "a[i]" << a[i].fi << ' ' << a[i].se << '\n';
    }

    for (int i = 1; i <= m; i++) {
        b[i].fi = std::lower_bound(buk.begin(), buk.end(), b[i].fi) - buk.begin() + 1;
        b[i].se = std::lower_bound(buk.begin(), buk.end(), b[i].se) - buk.begin() + 1;
        c[i].fi = std::lower_bound(buk.begin(), buk.end(), c[i].fi) - buk.begin() + 1;
        c[i].se = std::lower_bound(buk.begin(), buk.end(), c[i].se) - buk.begin() + 1;
        // cerr << "b[i]" << b[i].fi << ' ' << b[i].se << '\n';
        // cerr << "c[i]" << c[i].fi << ' ' << c[i].se << '\n';
    }


    int q = buk.size() + 1;
    vector<int> sum1(q + 1), sum2(q + 1);
    // cerr << "q:" << q << '\n';

    for (int i = 1; i <= m; i++) {
        sum1[b[i].fi]++, sum1[b[i].se + 1]--;
        sum2[c[i].fi]++, sum2[c[i].se + 1]--;
    }
    for (int i = 1; i <= q; i++) {
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
    }
    for (int i = 0; i <= q; i++) {
        sum1[i] = sum1[i] > 0 ? 1 : 0;
        sum2[i] = sum2[i] > 0 ? 1 : 0;
    }
    for (int i = 1; i <= q; i++) {
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
        // cerr << sum1[i] << ' ';
    }

    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        int x = a[i].fi, y = a[i].se;
        if (sum1[y - 1] - sum1[x] > 0) flag = 0;
        if (sum2[y] - sum2[x - 1] != (y - x + 1)) flag = 0;
    }
    puts(flag ? "Yes" : "No");

}

/*
*/

signed main() {
    // freopen("1004.in", "r", stdin);
    // freopen("1004.ans", "w", stdout);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}