#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m, x[N], y[N];
int ans, sum[N], f[N];
int time, top, Bcnt;
int num_edge, v[N], head[N];
int dfn[N], low[N], stack[N], belong[N];
bool instack[N];

struct Node
{
    int from, to, next;
} edge[M];

void add_edge(int u, int v)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].from = u;
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void Tarjan(int u)
{
    dfn[u] = low[u] = ++time;
    stack[++top] = u, instack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            Tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (instack[v])
            low[u] = std::min(low[u], low[v]);
    }
    if (dfn[u] == low[u])
    {
        Bcnt++;
        int k;
        do
        {
            k = stack[top--];
            instack[k] = false;
            belong[k] = Bcnt;
            sum[Bcnt] += v[k];
        } while (k != u);
    }
}

void dfs(int u)
{
    if (f[u])
        return;
    f[u] = sum[u];
    int max = 0;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
        max = std::max(max, f[v]);
    }
    f[u] += max;
    ans = std::max(ans, f[u]);
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
        scanf("%d", &v[i]);
    Rep(i, 1, m)
    {
        scanf("%d%d", &x[i], &y[i]);
        add_edge(x[i], y[i]);
    }
    Rep(i, 1, n)
    {
        if (!dfn[i])
            Tarjan(i);
    }
    memset(head, 0, sizeof(head));
    memset(edge, 0, sizeof(edge));
    Rep(i, 1, m)
    {
        if (belong[x[i]] != belong[y[i]])
            add_edge(belong[x[i]], belong[y[i]]);
    }
    Rep(i, 1, Bcnt)
        dfs(i);
    printf("%d", ans);
    return 0;
}