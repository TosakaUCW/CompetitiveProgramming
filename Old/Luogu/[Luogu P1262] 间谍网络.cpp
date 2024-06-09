#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int n, q, r, ans;
int cost[N], ind[N];
int head[N], num_edge;
int dfn[N], low[N], min[N];
int belong[N];
int timer, num_scc;
std::stack<int> S;
bool inStack[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
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
            min[num_scc] = std::min(min[num_scc], cost[x]);
            belong[x] = num_scc;
            inStack[x] = false;
            S.pop();
        } while (x != u);
    }
}

int main()
{
    memset(cost, 0x3f, sizeof cost);
    memset(min, 0x3f, sizeof min);
    n = read(), q = read();
    for (int i = 1, u, v; i <= q; i++)
        u = read(), v = read(), cost[u] = v;
    r = read();
    for (int i = 1, u, v; i <= r; i++)
        u = read(), v = read(), add_edge(u, v);
    for (int i = 1; i <= n; i++)
        if (!dfn[i] and cost[i] != cost[n + 1])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            printf("NO\n%d", i);
            return 0;
        }
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (belong[u] != belong[v])
                ind[belong[v]]++;
        }
    for (int i = 1; i <= num_scc; i++)
        if (!ind[i])
            ans += min[i];
    printf("YES\n%d", ans);
    return 0;
}