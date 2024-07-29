#include <bits/stdc++.h>
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
    int n = read(), m = read();
    string s; cin >> s;
    
    vector<std::array<int, 26>> f(m + 1);
    vector<std::array<int, 10>> g(m + 1);
    
    f[m].fill(m);
    for (int i = m - 1; i >= 0; i--)
    {
        f[i] = f[i + 1];
        if (isalpha(s[i])) f[i][s[i] - 'a'] = i;
    }
    g[0].fill(-1);
    for (int i = 0; i < m; i++)
    {
        g[i + 1] = g[i];
        if (isdigit(s[i])) g[i + 1][s[i] - '0'] = i;
    }
    
    
    vector<int> cnt(m + 1);
    for (int mm = 1; mm <= 12; mm++)
        for (int dd = 1; dd <= days[mm - 1]; dd++)
        {
            int p = m;
            for (auto x : {dd % 10, dd / 10, mm % 10, mm / 10})
            {
                p = g[p][x];
                if (p < 0) break;
            }
            if (p >= 0) cnt[p]++;
        }
        
    for (int i = m - 1; i >= 0; i--) cnt[i] += cnt[i + 1];
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string t; cin >> t;
        int p = 0;
        for (auto c : t)
        {
            p = f[p][c - 'a'] + 1;
            if (p > m) break;
        }
        if (p <= m) ans += cnt[p];
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