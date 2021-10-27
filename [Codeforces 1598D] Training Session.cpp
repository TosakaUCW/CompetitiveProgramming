#include <stdio.h>
#include <algorithm>
#include <mem.h>
#include <vector>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, ans, b[N];
std::vector<int> a[N];
#define pb emplace_back

void solve()
{
    n = read(), ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++)
        a[i].clear(), b[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read(), y = read();
        a[x].pb(y), b[y]++;
    }
    for (int i = 1; i <= n; i++)
        for (int x : a[i])
            ans -= (a[i].size() - 1) * (b[x] - 1);
    printf("%lld\n", ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}