#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
int n;
int a[N];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    bool f = 1;
    for (int i = 1; i < n; i++) f &= !(a[i] % a[i + 1]);
    if (f)
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
    else
        printf("-1");
    puts("");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}