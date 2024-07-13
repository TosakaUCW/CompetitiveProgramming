#include <bits/stdc++.h>

const int N = 5e6 + 5;

struct Node
{
    int a, b, c;
    bool friend operator < (Node a, Node b)
    {
        if (a.b == b.b and a.c == b.c)
            return a.a < b.a;
        if (a.b == b.b)
            return a.c < b.c;
        return a.b > b.b;
    }
} a[N];

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i].a = read(), a[i].b = read(), a[i].c = read();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i].a);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}