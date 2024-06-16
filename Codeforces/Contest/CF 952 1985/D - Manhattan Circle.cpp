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
    int n = read(), m = read();
    int max[2] = {1, 1}, min[2] = {n, m};
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            if (s[j] == '#')
            {
                max[0] = std::max(max[0], i + 1);
                min[0] = std::min(min[0], i + 1);
                max[1] = std::max(max[1], j + 1);
                min[1] = std::min(min[1], j + 1);
            }
    }
    cout << (max[0] + min[0]) / 2 << ' ' << (max[1] + min[1]) / 2 << '\n';
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