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

const int INF = 1 << 30;

void solve()
{
    int n = read();
    vector<int> cnt(n + 1), a(1);
    for (int i = 1; i <= n; i++) cnt[read()]++;
    for (int i = 1; i <= n; i++) if (cnt[i]) a.pb(cnt[i]);
    n = a.size() - 1;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INF));  

    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= 1 and f[i - 1][j - 1] + a[i] <= i - j)
                f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + a[i]);
        }
    
    int ans = INF;
    for (int i = 0; i <= n; i++)
        if (f[n][i] != INF) ans = std::min(ans, n - i);
    
    cout << ans << '\n';
}

/*
2 3 3 5 5 6 6 7 8 11 11
3 5 6 11
2 7 8 11
*/

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}