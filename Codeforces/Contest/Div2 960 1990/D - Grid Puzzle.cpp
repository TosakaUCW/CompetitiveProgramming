#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::min, std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

void solve()
{
    int n = read();
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    int las = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1) a[i] = 2;
        if (a[i] == 3) a[i] = 4;
        
        if (a[i] == 4 and !las) las = i;
        if (a[i] != 4 and a[i - 1] == 4) pos[i - 1] = las, las = 0;
    }
    
    
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (a[i] == 0 ? 0 : 1);
        
        if (a[i] == 2 and a[i - 1] == 2)
            dp[i] = min(dp[i], dp[i - 2] + 1);
        
        if (a[i] == 2 and a[i - 1] == 4)
        {
            if ((i - pos[i - 1]) % 2 == 0 and a[pos[i - 1] - 1] == 2)
                dp[i] = min(dp[i], dp[pos[i - 1] - 2] + i - (pos[i - 1] - 1));
        }
    }
    cout << dp[n] << '\n';
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