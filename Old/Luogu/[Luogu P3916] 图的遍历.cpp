#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;

int n, m, f[N];
int u[N], v[N];
int head[N], num_edge;

int num_scc, timer;
int dfn[N], low[N], belong[N], max[N];
bool inStack[N];
std::stack<int> S;

struct Node
{
    int next, to;
} edge[N << 1];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

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

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    S.push(u), inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++num_scc;
        int x;
        do
        {
            x = S.top(), S.pop(), inStack[x] = false;
            belong[x] = num_scc, max[num_scc] = std::max(max[num_scc], x);
        } while (x != u);
    }
}

void dfs(int u)
{
    if (f[u])
        return;
    f[u] = max[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
        f[u] = std::max(f[u], f[v]);
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        u[i] = read(), v[i] = read(), add_edge(u[i], v[i]);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    num_edge = 0;
    memset(head, 0, sizeof head);
    memset(edge, 0, sizeof edge);
    for (int i = 1; i <= m; i++)
        if (belong[u[i]] != belong[v[i]])
            add_edge(belong[u[i]], belong[v[i]]);
    for (int i = 1; i <= n; i++)
        dfs(i);
    for (int i = 1; i <= n; i++)
        printf("%d ", f[belong[i]]);
    return 0;
}