#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e5 + 5;

int n, ans;
int a[N];
std::vector<int> b[N];
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[a[i]].emplace_back(i);
    for (int i = 1; i <= n; i++)
        if (b[i].size() > 1)
            for (int j = 1, siz = b[i].size(); j < siz; j++)
                ans += (b[i][j] - b[i][j - 1] - 1) * j * (siz - j);
    printf("%lld", ans);
    return 0;
}