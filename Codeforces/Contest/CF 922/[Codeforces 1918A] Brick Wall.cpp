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
const int N = 1e6 + 5;
int n, a[N];

void solve()
{
    int n = read(), m = read();
        printf("%d\n", n * (m / 2));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}