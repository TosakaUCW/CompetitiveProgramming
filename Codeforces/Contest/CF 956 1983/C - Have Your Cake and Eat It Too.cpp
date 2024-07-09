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

void solve()
{
    int n = read();
    
    vector<vector<i64>> s(3, vector<i64>(n + 1));
    
    for(int i = 0; i < 3; i++)
        for(int j = 1; j <= n; j++)
            s[i][j] = s[i][j - 1] + read();
            
    i64 tot = s[0][n];

    vector<int> id{0, 1, 2};
    pii ans[3];
    
    do
    {
        int p1 = 0;
        while (s[id[0]][p1] * 3 < tot) p1++;
        int p2 = n + 1;
        while ((s[id[1]][n] - s[id[1]][p2 - 1]) * 3 < tot) p2--;
        
        if (p1 + 1 <= p2 - 1 and (s[id[2]][p2 - 1] - s[id[2]][p1]) * 3 >= tot)
        {
            ans[id[0]] = {1, p1};
            ans[id[1]] = {p2, n};
            ans[id[2]] = {p1 + 1, p2 - 1};
            break;
        }
        
    } while (std::next_permutation(id.begin(), id.end()));
    
    if (ans[0] == pii{0, 0}) cout << -1;
    else
        for (auto x : ans)
            cout << x.first << ' ' << x.second << ' ';
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