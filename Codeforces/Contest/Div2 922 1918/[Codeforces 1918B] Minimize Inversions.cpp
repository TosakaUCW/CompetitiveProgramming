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
int n;
struct Node
{
    int x, y;
    bool friend operator < (Node a, Node b)
    {
        return a.x + a.y < b.x + b.y;
    }
} a[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i].x = read();
    for (int i = 1; i <= n; i++) a[i].y = read();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) printf("%d ", a[i].x);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d ", a[i].y);
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}