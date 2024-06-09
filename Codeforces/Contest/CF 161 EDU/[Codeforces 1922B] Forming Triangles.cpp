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
const int N = 3e5 + 5;
int n, a[N];
int b[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 0; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) b[a[i]]++;
    long long ans = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (b[i] == 2)
            ans += cnt;
        if (b[i] > 2)
            ans += b[i] * (b[i] - 1) / 2 * cnt +
            b[i] * (b[i] - 1) * (b[i] - 2) / 6;
        cnt += b[i];
    }
    printf("%lld\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}