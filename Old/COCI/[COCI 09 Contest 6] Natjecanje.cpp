#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 15;
int n, s, r, ans;
bool a[N], b[N];
void solve()
{
    n = read(), s = read(), r = read();
    for (int i = 1; i <= s; i++) a[read()] = 1;
    for (int i = 1; i <= r; i++) b[read()] = 1;
    for (int i = 1; i <= n; i++)
        if (a[i])
            if (b[i - 1]) a[i] = b[i - 1] = 0;
            else if (b[i]) a[i] = b[i] = 0;
            else if (b[i + 1]) a[i] = b[i + 1] = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    printf("%d\n", ans);
}
signed main()
{
    solve();
    return 0;
}