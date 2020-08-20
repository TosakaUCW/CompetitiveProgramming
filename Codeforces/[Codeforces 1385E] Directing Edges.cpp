#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, m;
int ind[N], rk[N];
int head[N], num_edge;
std::queue<int> Q;
std::vector<std::pair<int, int>> V;

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

bool topo_sort()
{
    int tot = 0;
    while (!Q.empty())
        Q.pop();
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q.push(i);
    while (!Q.empty())
    {
        int u = Q.front();
        rk[u] = ++tot;
        Q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            ind[v]--;
            if (!ind[v])
                Q.push(v);
        }
    }
    return tot == n;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        num_edge = 0;
        V.clear();
        memset(rk, 0, sizeof rk);
        memset(ind, 0, sizeof ind);
        memset(head, 0, sizeof head);
        scanf("%d%d", &n, &m);
        for (int i = 1, u, v, opt; i <= m; i++)
        {
            scanf("%d%d%d", &opt, &u, &v);
            if (opt == 1)
                add_edge(u, v), ind[v]++;
            else
                V.push_back(std::make_pair(u, v));
        }
        if (!topo_sort())
        {
            puts("NO");
            continue;
        }
        puts("YES");
        for (int u = 1; u <= n; u++)
            for (int i = head[u]; i; i = edge[i].next)
                printf("%d %d\n", u, edge[i].to);
        for (int i = 0; i < V.size(); i++)
            if (rk[V[i].first] < rk[V[i].second])
                printf("%d %d\n", V[i].first, V[i].second);
            else
                printf("%d %d\n", V[i].second, V[i].first);
    }
    return 0;
}