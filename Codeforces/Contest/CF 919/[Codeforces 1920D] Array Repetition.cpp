#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int las[N], dp[N];

void solve()
{
    int n = read(), q = read();
    for (int i = 0; i <= n; i++) las[i] = dp[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int opt = read(), x = read();
        if (opt == 1)
            las[i] = x, dp[i] = dp[i - 1] + 1;
        else
            las[i] = las[i - 1],
            dp[i] = (x + 1) > 2e18 / dp[i - 1] ? (long long)2e18 : dp[i - 1] * (x + 1);
    }
    for (int k; q--; )
    {
        k = read();
        while (1)
        {
            int pos = std::lower_bound(dp + 1, dp + 1 + n, k) - dp;
            if (dp[pos] == k)
            {
                std::cout << las[pos] << ' ';
                break;
            }
            if (k % dp[pos - 1] == 0)
            {
                std::cout << las[pos - 1] << ' ';
                break;
            }
            k %= dp[pos - 1];
        }
    }
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}