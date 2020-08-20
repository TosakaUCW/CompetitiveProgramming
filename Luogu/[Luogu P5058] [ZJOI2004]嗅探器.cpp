#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 5;

int n, a, b;
int head[N], num_edge, timer;
int dfn[N], low[N];
bool cut[N];

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
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v), low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u] and u != a and dfn[b] >= dfn[v])
                cut[u] = true;
        }
        else
            low[u] = std::min(low[u], dfn[v]);
    }
}

int main()
{
    n = read();
    for (int u = read(), v = read(); u and v;)
        add_edge(u, v), add_edge(v, u), u = read(), v = read();
    a = read(), b = read();
    tarjan(a);
    for (int i = 1; i <= n; i++)
        if (cut[i])
        {
            printf("%d", i);
            return 0;
        }
    puts("No solution");
    return 0;
}