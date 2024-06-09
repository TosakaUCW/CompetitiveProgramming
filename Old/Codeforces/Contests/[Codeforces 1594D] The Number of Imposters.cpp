#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m;
int fa[N], siz[N];

int find(int x)
{
    if (x == fa[x])
        return x;
    fa[x] = find(fa[x]);
    siz[fa[x]] += siz[x], siz[x] = 0;
    return fa[x];
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx ^ fy)
        fa[fy] = fx, siz[fx] += siz[fy], siz[fy] = 0;
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n + n; i++)
        fa[i] = i, siz[i] = i <= n;
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        std::string str;
        std::cin >> str;
        if (str[0] == 'i')
            merge(x, y + n), merge(y, x + n);
        else
            merge(x, y), merge(x + n, y + n);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = find(i), y = find(n + i);
        if (x == y)
        {
            ans = -1;
            break;
        }
        ans += std::max(siz[x], siz[y]);
        siz[x] = siz[y] = 0;
    }
    printf("%d\n", ans);
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}