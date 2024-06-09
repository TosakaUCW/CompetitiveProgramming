#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve()
{
    int a = read(), b = read();
    int c = read(), d = read();
    if (a == c and b == d) puts("0");
    else if ((a + b) % 2 == (c + d) % 2) puts("2");
    else puts("1");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}