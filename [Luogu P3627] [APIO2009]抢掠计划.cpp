#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>

const int N = 5e5 + 5;

int n, m;
int a[N];
int u[N], v[N];
int head[N], num_edge;

bool inQ[N];
int dis[N];
std::queue<int> Q;

int num_scc,
    timer;
int dfn[N], low[N], belong[N], sum[N];
bool inStack[N];
std::stack<int> S;

struct Node
{
    int next, to, dis;
} edge[N];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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
            sum[num_scc] += a[x], belong[x] = num_scc;
        } while (x != u);
    }
}

void SPFA(int s)
{
    Q.push(s), inQ[s] = true;
    dis[s] = sum[s];
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(), inQ[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] < dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!inQ[v])
                    Q.push(v), inQ[v] = true;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P3627_1.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        u[i] = read(), v[i] = read(), add_edge(u[i], v[i], 0);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    num_edge = 0;
    memset(head, 0, sizeof head);
    memset(edge, 0, sizeof edge);
    for (int i = 1; i <= m; i++)
        if (belong[u[i]] != belong[v[i]])
            add_edge(belong[u[i]], belong[v[i]], sum[belong[v[i]]]);
    int S = read(), T = read(), ans = 0;
    SPFA(belong[S]);
    for (int i = 1, x; i <= T; i++)
        x = read(), ans = std::max(ans, dis[belong[x]]);
    printf("%d", ans);
    return 0;
}