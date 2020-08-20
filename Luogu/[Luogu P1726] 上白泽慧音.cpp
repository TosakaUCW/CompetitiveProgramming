#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <vector>

const int N = 5e5 + 5;

int n, m;
int head[N], num_edge;
int ans;

int num_scc, timer;
int dfn[N], low[N], belong[N], sum[N];
bool inStack[N];
std::stack<int> S;
std::vector<int> V[N];

struct Node
{
    int next, to;
} edge[N];

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
            belong[x] = num_scc, sum[num_scc]++, V[num_scc].push_back(x);
        } while (x != u);
        if (sum[num_scc] > ans)
            ans = num_scc;
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v, opt; i <= m; i++)
    {
        u = read(), v = read(), opt = read();
        add_edge(u, v);
        if (opt == 2)
            add_edge(v, u);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    std::sort(V[ans].begin(), V[ans].end());
    printf("%d\n", sum[ans]);
    for (int i = 0; i < V[ans].size(); i++)
        printf("%d ", V[ans][i]);
    return 0;
}