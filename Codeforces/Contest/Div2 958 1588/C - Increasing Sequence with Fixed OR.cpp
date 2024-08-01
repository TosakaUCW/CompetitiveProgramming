#include <bits/stdc++.h>
using i64 = long long;
#define int long long
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
    i64 n = read();
    vector<i64> res, ans;
    
    for (int i = 0; i <= 63; i++)
        if (n & (1LL << i))
            ans.pb(1LL << i);
    res.pb(n);
    for (auto x : ans)
        if (x < n) res.pb(n - x);
    
    std::reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';
    puts("");
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