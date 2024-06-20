#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e3 + 5;

i64 x[N], y[N], f[N][N];

void solve()
{
    int n = read();
    for (int i = 0; i < n; i++) x[i] = read(), y[i] = read();
    auto nxt = [&](i64 x) { return (x + 1) % n; };
    auto las = [&](i64 x) { return (x - 1 + n) % n; };
    auto dist = [&](int i, int j) { return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); };
    auto cross = [&](int x1, int y1, int x2, int y2) { return x1 * y2 - x2 * y1; };
    auto check = [&](int a, int b, int c) { return cross(x[b] - x[a], y[b] - y[a], x[c] - x[b], y[c] - y[b]) != 0; };
    for (int len = 2; len <= n; len++)
        for (int i = 0, j = len - 1; i < n; i++, j = nxt(j))
            f[i][j] = std::max({f[i][las(j)], f[nxt(i)][j], dist(i, j)});
    i64 ans = 1LL << 62;
    for (int i = 0; i < n; i++)
        for (int j = nxt(i); j != i; j = nxt(j))
            if (check(i, nxt(i), j) and check(j, nxt(j), i))
                ans = std::min(ans, f[i][j] + f[j][i]);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}