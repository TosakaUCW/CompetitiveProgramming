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

const int N = 5e6 + 5;
const int P = 1e9 + 7;

void solve()
{
    int n = read();
    std::map<std::string, int> mp;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        mp[s] = 1;
    }
    for (int q = read(); q--; )
    {
        int m = read(), cnt = 0;
        int newn = n;
        for (int i = 1; i <= m; i++)
        {
            string s; cin >> s;
            if (mp[s]) cnt++;
            else newn++;
        }
        double ans = 1.0 * cnt / newn;
        printf("%.2f\n", ans);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}