#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 100 + 5;
int n;
struct Node
{
    int x, y, z;
    bool friend operator< (Node a, Node b) { return std::max(a.y - b.x, 0) + b.y < std::max(b.y - a.x, 0) + a.y; }
} a[N];
void solve()
{
    for (int i = 1; i <= n; i++) a[i].x = read();
    for (int i = 1; i <= n; i++) a[i].y = read();
    for (int i = 1; i <= n; i++) a[i].z = std::max(a[i].y - a[i].x, 0) - a[i].y;
    // for (int i = 1; i <= n; i++) printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);
    std::sort(a + 1, a + 1 + n);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
        x -= a[i].x, x = std::max(x, 0), y += a[i].x, x += a[i].y;
    printf("%d\n", x + y);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF)
        solve();
    return 0;
}