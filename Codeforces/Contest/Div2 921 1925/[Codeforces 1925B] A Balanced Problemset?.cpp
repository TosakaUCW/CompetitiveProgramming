#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
// #define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 3e5 + 5;
int n, a[N];
int b[N];

void solve()
{
    int x = read(), n = read(), ans = 1;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            if (n <= x / i) ans = std::max(ans, i);
            if (n <= i) ans = std::max(ans, x / i);
        }
    std::cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}