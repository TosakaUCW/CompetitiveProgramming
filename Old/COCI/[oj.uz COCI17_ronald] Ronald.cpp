#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stdlib.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m, cnt;
bool vis[N];
std::vector<int> G[N];

void dfs(int u, int last = -1)
{
    if (last != -1 and G[u].size() != last)
        puts("NE"), exit(0);
    vis[u] = true;
    for (auto v : G[u])
        if (!vis[v])
            dfs(v, G[u].size());
}

int main()
{
    freopen("ronald.in", "r", stdin), freopen("ronald.out", "w", stdout);
    n = read(), m = read();
    for (int u, v; m--;)
        u = read(), v = read(),
        G[u].push_back(v), G[v].push_back(u);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i), cnt++;
    return puts(cnt > 2 ? "NE" : "DA"), 0;
}