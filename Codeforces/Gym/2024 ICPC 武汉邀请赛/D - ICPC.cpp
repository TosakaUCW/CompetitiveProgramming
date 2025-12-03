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
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    vector<vector<i64>> f(n + 1, vector<i64>(2 * n + 1, 0));
    
    auto go = [&](vector<i64> &a, vector<vector<i64>> &f)
    {
        vector<vector<i64>> g(n + 1, vector<i64>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            g[i][0] = a[i];
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = g[i][j - 1];
                if (i + j <= n) g[i][j] += a[i + j];
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 2 * n; j++)
                f[i][j] = std::max(f[i][j], std::max(f[i - 1][j - 1], g[i][std::min(j, n)]));
    };
    
    go(a, f);

    std::reverse(a.begin() + 1, a.end());
    std::reverse(f.begin() + 1, f.end());
    go(a, f);
    
    std::reverse(f.begin() + 1, f.end());
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        i64 now = 0;
        for (i64 j = 1; j <= 2 * n; j++)
            now ^= j * f[i][j];
        ans ^= now + i;
    }
    cout << ans << '\n';
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