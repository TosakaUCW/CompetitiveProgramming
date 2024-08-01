#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, m, a[N][N], f[N][N];
void upd(int &x, int y) { x = std::min(x, y); }
void solve()
{
    n = read(), m = read();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = read(), f[i][j] = -1;
    std::queue<pii> q;
    q.emplace(0, 0), f[0][0] = 0;
    int ans = INT_MAX;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (y == m - 1)
            ans = std::min(ans, f[x][y] + ((x  - (n - 1 + f[x][y])) % n + n) % n);
        if (f[(x + 1) % n][y + 1] == -1 and a[(x + 1) % n][y + 1] == 0 and y + 1 < m)
            f[(x + 1) % n][y + 1] = f[x][y] + 1,
            q.emplace((x + 1) % n, y + 1);
        if (f[(x + 2) % n][y] == -1 and a[(x + 1) % n][y] == 0 and a[(x + 2) % n][y] == 0)
            f[(x + 2) % n][y] = f[x][y] + 1,
            q.emplace((x + 2) % n, y);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}