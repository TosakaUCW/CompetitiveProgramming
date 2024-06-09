#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m;
int  head[N], num_edge;
int u[N], v[N];
int sum[N];

int dfn[N], low[N], timer;
std::stack<int> S;
int num_scc, belong[N];
bool inStack[N];

int f[N], ans;

struct Node
{
    int next, to;
} edge[M];

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

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    S.push(u);
    inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], low[v]);
    }
    if (low[u] == dfn[u])
    {
        ++num_scc;
        int x;
        do
        {
            x = S.top();
            sum[num_scc]++;
            belong[x] = num_scc;
            inStack[x] = false;
            S.pop();
        } while (x != u);
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        u[i] = read(), v[i] = read(), add_edge(u[i], v[i]);
    for (int u = 1; u <= n; u++)
        if (!dfn[u])
            tarjan(u);
    for (int i = 1; i <= num_scc; i++)
        if (sum[i] > 1)
            ans++;
    printf("%d", ans);
    return 0;
}