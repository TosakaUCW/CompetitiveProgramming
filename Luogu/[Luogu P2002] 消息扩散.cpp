#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m, ans;
int head[N], num_edge, ind[N];

int num_scc, timer;
int dfn[N], low[N], belong[N];
bool inStack[N];
std::stack<int> S;

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
    S.push(u), inStack[u] = true;
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
            x = S.top(), S.pop(), inStack[x] = false, belong[x] = num_scc;
        while (x != u);
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i <= m; i++)
    {
        u = read(), v = read();
        if (u != v)
            add_edge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (belong[u] != belong[v])
                ind[belong[v]]++;
        }
    for (int i = 1; i <= num_scc; i++)
        ans += !ind[i];
    printf("%d", ans);
    return 0;
}