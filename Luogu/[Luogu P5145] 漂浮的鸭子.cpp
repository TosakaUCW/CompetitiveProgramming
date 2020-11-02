#include <stdio.h>
#include <algorithm>
#include <stack>

const int N = 1e5 + 5;
const int M = N << 1;

int n, num_scc, ans;
int head[N], num_edge;
int dfn[N], belong[N], low[N], size[N];
std::stack<int> S;
bool inStack[N];

struct Node
{
    int next, to, dis;
} edge[M];

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
    dfn[u] = low[u] = ++dfn[0], S.push(u), inStack[u] = true;
    for (int i = head[u], v; i; i = edge[i].next)
    {
        if (!dfn[v = edge[i].to])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (inStack[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int x;
        num_scc++;
        do
        {
            x = S.top(), S.pop(), inStack[x] = false, belong[x] = num_scc;
        } while (x != u);
    }
}

int main()
{
    n = read();
    for (int u = 1, v, dis; u <= n; u++)
        v = read(), dis = read(), add_edge(u, v, dis);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
        for (int i = head[u], v; i; i = edge[i].next)
            if (belong[u] == belong[v = edge[i].to])
                size[belong[u]] += edge[i].dis, ans = std::max(ans, size[belong[u]]);
    return printf("%d", ans), 0;
}