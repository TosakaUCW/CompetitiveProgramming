#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

const int N = 3e5 + 5;
const int M = 6e5 + 5;

int n, m, s, num_edge;
int ans[N];
bool vis[N];

struct Node
{
    int v, type, idx;
};

std::vector<Node> G[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dfs1(int u)
{
    vis[u] = true;
    for (int i = 0, v; i < G[u].size(); i++)
        if (!vis[v = G[u][i].v])
        {
            ans[0]++;
            if (G[u][i].type == 1)
                dfs1(v);
            else if (G[u][i].type == 2)
                ans[G[u][i].idx] = 1, dfs1(v);
            else
                ans[G[u][i].idx] = 0, dfs1(v);
        }
}

void dfs2(int u)
{
    vis[u] = true;
    for (int i = 0, v; i < G[u].size(); i++)
        if (!vis[v = G[u][i].v])
        {
            if (G[u][i].type == 1)
                ans[0]++, dfs2(v);
            else if (G[u][i].type == 2)
                ans[G[u][i].idx] = 0;
            else
                ans[G[u][i].idx] = 1;
        }
}

int main()
{
    n = read(), m = read(), s = read();
    for (int i = 1, opt, u, v; i <= m; i++)
    {
        opt = read(), u = read(), v = read();
        if (opt == 1)
            G[u].push_back(Node{v, 1, 0});
        else
        {
            G[u].push_back(Node{v, 2, ++num_edge});
            G[v].push_back(Node{u, 3, num_edge});
        }
    }
    dfs1(s), printf("%d\n", ans[0] + 1);
    for (int i = 1; i <= num_edge; i++)
        putchar(ans[i] ? '+' : '-');
    memset(vis, 0, sizeof vis), memset(ans, 0, sizeof ans);
    dfs2(s), printf("\n%d\n", ans[0] + 1);
    for (int i = 1; i <= num_edge; i++)
        putchar(ans[i] ? '+' : '-');
    return 0;
}