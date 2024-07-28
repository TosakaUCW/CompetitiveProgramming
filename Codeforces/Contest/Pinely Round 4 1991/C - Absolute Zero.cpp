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

const int N = 2e5 + 5;

void solve()
{
    int n = read();
    vector<int> a(n + 1), ans;
    for (int i = 1; i <= n; i++) a[i] = read();
    #define ins insert
    std::set<int> S;
    for (int i = 1; i <= n; i++) S.ins(a[i]);
    
    for (int t = 1; t <= 50; t++)
    {
        std::set<int> T;
        
        auto mn = *S.begin();
        auto mx = *S.rbegin();
        
        if (mn == 0 and mx == 0) break;
        
        int mid = (mn + mx) / 2;
        ans.pb(mid);
        for (auto x : S) T.ins(abs(x - mid));
        S = T;
    }
    if (ans.size() > 40) puts("-1");
    else
    {
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        puts("");
    }
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
80 40 20 10

35 5 25 35
15 15 5 15
5 5 5 5
0 0 0 0


20 20 40 50
20 20 0 10
0 0 20 10
10 10 10 0
20 20 20 30
5 5 5 5
0 0 0 0
*/