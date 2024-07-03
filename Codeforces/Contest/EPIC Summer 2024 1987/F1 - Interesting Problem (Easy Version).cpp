#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::min, std::max, std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    int n = read();
    vector<int> a(n + 1), g(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 1e9)); 
    for (int i = 1; i <= n; i++) a[i] = read();
    
    for (int len = 2; len <= n; len += 2)
        for (int l = 1, r = len; r <= n; l++, r++)
            if (a[l] <= l and (l - a[l]) % 2 == 0)
            {
                int t = (l - a[l]) / 2;
                if (len == 2 or f[l + 1][r - 1] <= t)
                    f[l][r] = t;
                for (int k = l + 1; k <= r - 1; k += 2)
                    f[l][r] = min(f[l][r], max({t, f[l][k], f[k + 1][r] - (k - l + 1) / 2}));
            }
        
    for (int i = 1; i <= n; i++)
    {
        g[i] = g[i - 1];
        for (int j = i - 1; j >= 1; j -= 2)
            if(f[j][i] <= g[j - 1]) 
                g[i] = max(g[i], g[j - 1] + (i - j + 1) / 2);
    }
    
    cout << g[n] << '\n';
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