#include <bits/stdc++.h>
using i64 = long long;
#define int long long
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

using std::max, std::min;

void solve()
{
    i64 n = read(), k = read();
    vector<i64> a(n + 1);
    std::map<i64, i64> mp;
    
    for (int i = 1; i <= n; i++) mp[read()]++;
    
    i64 ans = 0;
   
    for (auto [x, y] : mp)
    {
        ans = max(ans, x * min(y, k / x));
        if (mp.count(x + 1))
        {
            i64 z = mp[x + 1];
            i64 c;
            
            if (x * y >= k) c = k / x;
            else c = y + min(z, (k - x * y) / (x + 1));
            
            ans = max(ans, min(k, c * x + min(c, z)));
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