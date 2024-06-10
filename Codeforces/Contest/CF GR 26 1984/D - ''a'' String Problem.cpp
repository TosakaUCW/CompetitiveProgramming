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

const int N = 2e5;

void solve()
{
    string s; cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), 'a') == n)
        return printf("%d\n", n - 1), void();
    vector<int> p;
    for (int i = 0; i < n; i++) if (s[i] != 'a') p.pb(i);
    
    int m = p.size();
    i64 ans = 0;
    
    auto check = [&](int len)
    {
        // cout << len << '\n';
        bool flag = 1;
        for (int j = len; j < m; j++)
        {
            int k = j % len;
            if (s[p[j]] != s[p[k]] or (k and p[k] - p[k - 1] != p[j] - p[j - 1]))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            int min = n;
            for (int j = len; j < m; j += len)
                min = std::min(min, p[j] - p[j - 1] - 1);
                
            for (int x = 0; x <= p[0]; x++)
                ans += std::max(0, std::min(min - x + 1, n - p.back()));
        }
    };
    
    for (int i = 1; i * i <= m; i++)
        if (m % i == 0)
        {
            check(i);
            if (i != m / i) check(m / i);
        }
        
    cout << ans << '\n';
    
    #ifndef ONLINE_JUDGE
        puts("-----------");
    #endif
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