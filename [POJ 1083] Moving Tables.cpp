#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
int a[N];
void solve()
{
    memset(a, 0, sizeof a);
    for (int n = read(); n--; )
    {
        int x = read() - 1 >> 1;
        int y = read() - 1 >> 1;
        if (x > y) std::swap(x, y);
        for (int i = x; i <= y; i++) a[i]++;
    }
    int ans = 0;
    for (int i = 0; i <= 200; i++) ans = std::max(ans, a[i]);
    printf("%d\n", ans * 10);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}