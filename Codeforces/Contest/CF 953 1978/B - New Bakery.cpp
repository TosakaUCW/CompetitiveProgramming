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

void solve()
{
    i64 n = read(), a = read(), b = read();
    i64 k = b + 1 - a;
    if (k <= 0) k = 0;
    if (k >= std::min(n, b)) k = std::min(n, b);
    // cout << k << ' ';
    i64 ans = 0;
    ans = (b + b - k + 1) * k / 2 + (n - k) * a;
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