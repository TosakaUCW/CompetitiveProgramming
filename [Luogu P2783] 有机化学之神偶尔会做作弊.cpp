#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;
const int M = 25;

int n, m;
int u[N], v[N];
int head[N], num_edge;

int num_scc, timer;
int dfn[N], low[N], belong[N];
bool inStack[N];
std::stack<int> S;

int depth[N], fa[N][M + 5];

struct Node
{
    int next, to;
} edge[N];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++timer;
    S.push(u), inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        if (!dfn[v])
            tarjan(v, u), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++num_scc;
        int x;
        do
        {
            x = S.top(), S.pop(), inStack[x] = true, belong[x] = num_scc;
        } while (x != u);
    }
}

void dfs(int u, int fath)
{
    depth[u] = depth[fath] + 1;
    fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs(v, u);
    }
}

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

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = M; ~i; i--)
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = M; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void print(int x)
{
    if (!x)
        return;
    print(x >> 1);
    printf("%d", x & 1);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        u[i] = read(), v[i] = read(), add_edge(u[i], v[i]), add_edge(v[i], u[i]);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0);
    num_edge = 0;
    memset(head, 0, sizeof head);
    memset(edge, 0, sizeof edge);
    for (int i = 1; i <= m; i++)
        if (belong[u[i]] != belong[v[i]])
            add_edge(belong[u[i]], belong[v[i]]), add_edge(belong[v[i]], belong[u[i]]);
    dfs(belong[1], 0);
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    for (int q = read(), x, y; q; q--, puts(""))
    {
        x = read(), y = read();
        x = belong[x], y = belong[y];
        print(depth[x] + depth[y] - 2 * depth[lca(x, y)] + 1);
    }
    return 0;
}