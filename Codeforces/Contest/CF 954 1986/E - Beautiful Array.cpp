#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    int n = read(), k = read(), cnt = 0;
    vector<int> a(n), b;
    std::map<int, int> mp, rem;
    for (int i = 0; i < n; i++) mp[a[i] = read()]++;
    for (auto [x, y] : mp)
        if (y % 2 != 0)
            b.pb(x);
    std::sort(b.begin(), b.end());
    
    // cout << k << " : ";
    // for (auto x : b) cout << x << ' ';
    
    vector<vector<int>> buk(n + 1);
    for (auto x : b)
    {
        int r = x % k;
        if (rem[r] == 0) rem[r] = ++cnt;
        buk[rem[r]].pb(x / k);
    }
    
    
    // printf("++%d++", rem[0]);
    
    int flag = 0, ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int siz = buk[i].size();
        if (siz % 2 == 1)
        {
            flag++;
            
            // printf("-- %d %d\n", siz, buk[i][0]);
            
            vector<int> sum(siz + 1, 0);
            sum[0] = -buk[i][0];
            for (int j = 1, opt = 1; j < siz; j++, opt *= -1)
                sum[j] = sum[j - 1] + opt * buk[i][j];
            int res = -(sum[siz - 1] - sum[0]);   
            for (int i = 1; i < siz; i++)
            {
                res = std::min(res, sum[i - 1] - (sum[siz - 1] - sum[i]));
            }
            ans += res;
        }
        else
        {
            for (int j = 1; j < siz; j += 2)
                ans += buk[i][j] - buk[i][j - 1];
        }
    }
    cout << (flag <= 1 ? ans : -1) << '\n';
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
/*
0: 3, 9, 18, 30
1 3 6 10
1: 1, 4, 10, 22, 28
2: 2, 14, 17, 20
*/