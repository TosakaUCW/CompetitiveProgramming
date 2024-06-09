#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define x first
#define y second
typedef std::pair<int, int> Node;
int calc(Node a, Node b, Node c)
{
    Node i = {a.x - b.x, a.y - b.y};
    Node j = {c.x - b.x, c.y - b.y};
    return i.x * j.y - j.x * i.y;
}
int f[4];
Node a[4];
void solve()
{
    for (int i = 0; i < 4; i++)
        a[i].x = read(), a[i].y = read();
    f[0] = calc(a[0], a[1], a[2]);
    f[1] = calc(a[1], a[2], a[3]);
    f[2] = calc(a[2], a[3], a[0]);
    f[3] = calc(a[3], a[0], a[1]);
    bool flag = 1;
    // for (int i = 0; i < 4; i++) printf("%d\n", f[i]);
    for (int i = 0; i < 4; i++) flag &= (f[i] < 0);
    puts(flag ? "Yes" : "No");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}