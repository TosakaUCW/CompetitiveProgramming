#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>

const int N = 1e5 + 5;

int n, m;
int ind[N], head[N], num_edge;
int ans[N], tot;

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

void topo_sort()
{
    std::priority_queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q.push(i);
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop(), ans[++tot] = u;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            ind[v]--;
            if (!ind[v])
                Q.push(v);
        }
    }
    if (tot < n)
        printf("Impossible!");
    else
        for (int i = n; i; i--)
            printf("%d ", ans[i]);
    puts("");
}

int main()
{
    for (int T = read(); T; T--)
    {
        tot = num_edge = 0;
        memset(ind, 0, sizeof ind);
        memset(ans, 0, sizeof ans);
        memset(head, 0, sizeof head);
        memset(edge, 0, sizeof edge);
        n = read(), m = read();
        for (int i = 1, u, v; i <= m; i++)
            u = read(), v = read(), add_edge(v, u), ind[u]++;
        topo_sort();
    }
    return 0;
}