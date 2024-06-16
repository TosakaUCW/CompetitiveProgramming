#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, i64 f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    i64 x = read(), y = read(), z = read(), k = read();
    i64 ans = 0;
    for (int a = 1; a <= x; a++)
    {
        for (int b = 1; b <= y; b++)
        {
            i64 c = k / a / b;
            if (c * a * b == k and c <= z)
                ans = std::max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
        }
    }
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