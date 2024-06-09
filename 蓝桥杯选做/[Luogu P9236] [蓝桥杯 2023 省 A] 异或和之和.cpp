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
int n, ans, sum[N], f[22][2];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ read();
    for (int j = 0; j <= 20; j++)
        for (int i = 0; i <= n; i++)
            f[j][(sum[i] >> j) & 1]++;
    for (int j = 0; j <= 20; j++) ans += (1LL << j) * f[j][0] * f[j][1];
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}