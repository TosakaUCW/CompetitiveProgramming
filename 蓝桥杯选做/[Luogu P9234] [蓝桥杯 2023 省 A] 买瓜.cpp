#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
// const int INF = 1e18;
int n, m, a[N], ans = 31;
std::unordered_map<int, int> vis;
void dfs(int l, int r, int cnt, int sum, bool flag)
{
    // cout << l << r << cnt << sum << '\n';
    if (sum > m or cnt >= ans) return;
    if (l == r + 1)
    {
        if (flag)
            vis[sum] = vis[sum] ? std::min(vis[sum], cnt + 1) : cnt + 1;
        else
            if (vis[m - sum]) ans = std::min(ans, vis[m - sum] + cnt - 1);
        return;
    }
    dfs(l + 1, r, cnt, sum, flag);
    dfs(l + 1, r, cnt + 1, sum + a[l] / 2, flag);
    dfs(l + 1, r, cnt, sum + a[l], flag);
}
void solve()
{
    n = read(), m = read() * 2;
    for (int i = 1; i <= n; i++) a[i] = read() * 2;
    std::sort(a + 1, a + 1 + n);
    dfs(1, n / 2, 0, 0, 1), dfs(n / 2 + 1, n, 0, 0, 0);
    if (ans < 31) cout << ans;
    else puts("-1");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}