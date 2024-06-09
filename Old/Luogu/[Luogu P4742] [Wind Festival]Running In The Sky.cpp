#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 2e6 + 5;
const int M = 5e6 + 5;

int n, m;
int u[M], v[M], val[N];
int head[N], num_edge;

int timer, num_scc;
int belong[N], dfn[N], low[N], sum[N], max[N];
bool inStack[N];
std::stack<int> S;

int ans_sum, ans_max;
int f[N], g[N];

struct Node
{
    int next, to;
} edge[M];

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
            x = S.top(), S.pop(), inStack[x] = false, belong[x] = num_scc;
            sum[num_scc] += val[x], max[num_scc] = std::max(max[num_scc], val[x]);
        } while (x != u);
    }
}

void dfs(int u)
{
    if (f[u])
        return;
    f[u] = sum[u], g[u] = max[u];
    int res1 = 0, res2 = 0;
    for (int i = head[u], v; i; i = edge[i].next)
    {
        dfs(v = edge[i].to);
        if (f[v] > res1)
            res1 = f[v], res2 = g[v];
        else if (f[v] == res1)
            res2 = std::max(res2, g[v]);
    }
    f[u] += res1, g[u] = std::max(g[u], res2);
    if (f[u] > ans_sum)
        ans_sum = f[u], ans_max = g[u];
    else if (f[u] == ans_sum)
        ans_max = std::max(ans_max, g[u]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();
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
    for (int i = 1; i <= num_scc; i++)
        dfs(i);
    printf("%d %d", ans_sum, ans_max);
    return 0;
}