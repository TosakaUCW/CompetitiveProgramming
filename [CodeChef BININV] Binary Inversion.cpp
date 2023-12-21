#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve()
{
    int n = read(), m = read(), las = 0, ans = 0;
    std::vector<std::pair<int, int>> a;
    for (int i = 1; i <= n; i++)
    {
        std::string s;
        std::cin >> s;
        int x = 0;
        for (auto ch : s)
            if (ch == 48)
                ans += x;
            else
                x++;
        a.emplace_back(std::make_pair(x, m - x));
    }
    std::sort(a.begin(), a.end());
    for (auto x : a)
        ans += las * x.second, las += x.first;
    printf("%lld\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}