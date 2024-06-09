#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>
#include <stdlib.h>

#define nosol puts("-1"), exit(0)

const int N = 2e5 + 5;
const int M = 4e5 + 5;

int n, m, k;
int ind[N], ans[N];
int min[N], max[N];
int head[N], num_edge;
std::queue<int> Q;
std::vector<int> V[N];
std::priority_queue<std::pair<int, int>> PQ;

struct Node
{
    int next, to;
} edge[M];
struct Edge
{
    int u, v;
} e[M];

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

void topo_sort(int opt)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q.push(i);
    for (int u; !Q.empty();)
    {
        u = Q.front(), Q.pop(), ++cnt;
        if (min[u] > max[u])
            nosol;
        for (int i = head[u], v; i; i = edge[i].next)
        {
            ind[v = edge[i].to]--;
            if (opt)
                min[v] = std::max(min[v], min[u] + 1);
            else
                max[v] = std::min(max[v], max[u] - 1);
            if (!ind[v])
                Q.push(v);
        }
    }
    if (cnt != n)
        nosol;
}

int main()
{
    n = read(), m = read(), k = read();
    for (int i = 1, x; i <= n; i++)
        (x = read()) ? (min[i] = max[i] = x) : (min[i] = 1, max[i] = k);
    for (int i = 1; i <= m; i++)
        e[i].u = read(), e[i].v = read();
    for (int i = 1; i <= m; i++)
        add_edge(e[i].u, e[i].v), ind[e[i].v]++;
    topo_sort(0);
    num_edge = 0, memset(head, 0, sizeof head), memset(edge, 0, sizeof edge);
    for (int i = 1; i <= m; i++)
        add_edge(e[i].v, e[i].u), ind[e[i].u]++;
    topo_sort(1);
    for (int i = 1; i <= n; i++)
        V[max[i]].push_back(i);
    for (int i = k, x; i >= 1; i--)
    {
        for (int j = 0; j < V[i].size(); j++)
            PQ.push(std::make_pair(min[V[i][j]], V[i][j]));
        if (PQ.empty())
            nosol;
        x = PQ.top().second, PQ.pop(), ans[x] = i;
        while (!PQ.empty())
        {
            x = PQ.top().second;
            if (min[x] < i)
                break;
            PQ.pop(), ans[x] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}