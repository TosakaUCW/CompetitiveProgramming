#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
int n, m, a[N], b[N];
int c[N], d[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    b[1] = 2, b[n] = 1;
    for (int i = 2; i < n; i++)
        b[i] = a[i] - a[i - 1] > a[i + 1] - a[i] ? 2 : 1;
    c[1] = a[1];
    for (int i = 1; i < n; i++)
        c[i + 1] = b[i] == 1 ? c[i] + a[i + 1] - a[i] : c[i] + 1;
    d[n] = a[n];
    for (int i = n; i >= 2; i--)
        d[i - 1] = b[i] == 1 ? d[i] - 1 : d[i] - a[i] + a[i - 1];
    for (int q = read(); q--; )
    {
        int x = read(), y = read();
        printf("%d\n", x > y ? d[x] - d[y] : c[y] - c[x]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}