#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m;
int a[N], b[N], c[N];
bool vis[N];

void solve()
{
    n = read(), m = read();
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i++)
    {
        a[i] = read(), b[i] = read(), c[i] = read();
        vis[b[i]] = 1;
    }
    int B = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) B = i;
    for (int i = 1; i <= n; i++)
        if (i ^ B)
            printf("%d %d\n", B, i);
}

int main()
{
    for (int T = read(); T--; solve());
    return 0;
}
