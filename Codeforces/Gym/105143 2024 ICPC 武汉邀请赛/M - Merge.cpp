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

void solve()
{
    int n = read();
    vector<int> a(n + 1), ans;
    std::map<int, int> mp;
    
    for (int i = 1; i <= n; i++) mp[a[i] = read()]++;
    std::sort(a.begin() + 1, a.end());
    
    auto find = [&](int x)
    {
        vector<int> tmp;
        std::function<bool(int)> check = [&](int y)
        {
            if (mp[y]) 
            {
                mp[y]--, tmp.pb(y);
                return 1;
            }
            else
            {
                if (y % 2 == 0 or y == 1) return 0;
                if (check(y / 2) and check(y / 2 + 1)) return 1;
                else return 0;
            }
        };
        if (check(x)) return 1;
        else
        {
            for (auto x : tmp) mp[x]++;
            return 0;
        }
    };
    
    
    for (int i = n; i; i--)
        if (a[i] % 2 == 0 and mp[a[i]])
        {
            mp[a[i]]--;
            if (find(a[i] + 1))
                mp[2 * a[i] + 1]++;
            else if (find(a[i] - 1))
                mp[2 * a[i] - 1]++;
            else
                mp[a[i]]++;
        }
        
    for (auto [a, b] : mp)
        for (int i = 0; i < b; i++)
            ans.pb(a);
    std::sort(ans.rbegin(), ans.rend());
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    solve();
    return 0;
}