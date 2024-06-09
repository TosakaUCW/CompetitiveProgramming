#include <stdio.h>
#include <algorithm>

const int N = 5e5 + 5;
const int M = N << 1;

int n, root;
long long ans, max[N];
int head[N], num_edge;

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

void dfs(int u, int fa)
{
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs(v, u), max[u] = std::max(max[u], max[v] + edge[i].dis);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            ans += max[u] - max[v] - edge[i].dis;
}

int main()
{
    n = read(), root = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs(root, 0);
    printf("%lld", ans);
    return 0;
}