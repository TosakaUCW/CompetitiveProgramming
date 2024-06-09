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

void solve()
{
    int a = read(), b = read(), r = read();
    int k = 0, ans = 0;
    if (a < b) std::swap(a, b);
    for (int i = 63; i >= 0; i--)
        if (((a >> i) & 1LL) == 1 and ((b >> i) & 1LL) == 0) { k = i; break; }
    // printf("k : %lld\n", k);
    for (int i = k - 1; i >= 0; i--)
    {
        int x = (a >> i) & 1LL, y = (b >> i) & 1LL;
        if (x == 1 and y == 0)
        {
            if (ans + (1LL << i) <= r)
                ans += 1LL << i;
        }
    }
    // printf("[%lld]\n", ans);
    int x = a ^ ans;
    int y = b ^ ans;
    printf("%lld\n", x - y);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}