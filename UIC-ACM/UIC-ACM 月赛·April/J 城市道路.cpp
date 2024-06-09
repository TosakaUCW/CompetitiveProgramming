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
const int P = 998244353;
int n, a[N], sum[35], g[N];
void solve()
{
    n = read();
    memset(sum, 0, sizeof sum);
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++) a[i] = read();
    g[1] = 1;
    for (int j = 0; j <= 30; j++)
            if ((a[1] >> j) & 1)
                sum[j] += g[1], sum[j] %= P;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 30; j++)
            if ((a[i] >> j) & 1)
                g[i] += sum[j], g[j] %= P;
        for (int j = 0; j <= 30; j++)
            if ((a[i] >> j) & 1)
                sum[j] += g[i], sum[j] %= P;
    }
    cout << g[n] % P << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("J.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}