#include <stdio.h>
#include <algorithm>
#include <mem.h>
#include <vector>
#include <iostream>
#include <string>
#include <queue>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 4e5 + 5;

int n, k, m, deg[N];
std::vector<int> g[N];
std::queue<int> Q[2];
#define pb emplace_back

void solve()
{
    n = read(), k = read(), m = n;
    for (int i = 1; i <= n; i++)
        g[i].clear(), deg[i] = 0;
    while (!Q[0].empty())
        Q[0].pop();
    while (!Q[1].empty())
        Q[1].pop();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(),
        g[u].pb(v), g[v].pb(u),
        deg[u] += 2, deg[v] += 2;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 2)
            Q[0].push(i);
    for (int i = 1, j = 0; i <= k; i++, j ^= 1)
    {
        if (m == 1 or m == 2)
        {
            m = 0;
            break;
        }
        for (int x; !Q[j].empty();)
        {
            x = Q[j].front(), Q[j].pop(), m--;
            for (auto v : g[x])
            {
                deg[v] -= 2;
                if (deg[v] == 2)
                    Q[j ^ 1].push(v);
            }
        }
    }
    printf("%d\n", m);
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}