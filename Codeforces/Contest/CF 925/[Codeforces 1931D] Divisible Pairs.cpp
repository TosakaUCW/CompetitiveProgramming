#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const long long INF = 1LL << 60;
int n, a[N];
void solve()
{
    int n = read(), x = read(), y = read(), res = 0;
    std::map<int, std::vector<int>> cnt;
    for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i] % y].pb(a[i]);
    for (auto map : cnt)
    {
        std::map<int, int> buk;
        auto vec = map.second;
        std::map<int, int> vis;
        for (auto i : vec) buk[i % x]++;
        for (auto i : vec)
            if (!vis[i % x])
                vis[i % x] = vis[x - i % x] = 1,
                res += i % x == x - i % x ?
                        buk[i % x] * (buk[i % x] - 1) / 2 :
                        buk[i % x] * buk[x - i % x];
        res += buk[0] * (buk[0] - 1) / 2;
    }
    cout << res << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}