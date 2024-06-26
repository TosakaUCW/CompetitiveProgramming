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

const int N = 5e5;
vector<int> divs[N + 1];

void solve()
{
    int n = read();
    i64 ans = 0;
    vector<int> a(n + 1);
    vector<vector<int>> pos1(n + 1), pos2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int gcd = std::__gcd(i, a[i] = read());
        if (gcd == i) ans--;
        pos1[i / gcd].pb(a[i] / gcd);
        pos2[a[i] / gcd].pb(i / gcd);
    }
    vector<int> cnt(n + 1);
    
    for (int y = 1; y <= n; y++)
    {
        if (pos1[y].empty()) continue;
        
        for (int u = y; u <= n; u += y)
            for (auto v : pos2[u])
                cnt[v]++;
                
        for (auto x : pos1[y])
            for (auto v : divs[x])
                ans += cnt[v];
                
        for (int u = y; u <= n; u += y)
            for (auto v : pos2[u])
                cnt[v]--;
    }
    
    cout << ans / 2 << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif

    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i)
            divs[j].push_back(i);
    
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}