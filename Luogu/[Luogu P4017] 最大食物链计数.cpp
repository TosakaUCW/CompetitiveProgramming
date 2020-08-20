#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 5e3 + 5;
const int M = 5e5 + 5;
const int P = 80112002;

int n, m;
int head[N], num_edge;
int ind[N], oud[N];
long long f[N], ans;
std::queue<int> Q;

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

void topo_sort()
{
    for (int i = 1; i <= n; i++)
        if (ind[i] == 0)
            Q.push(i), f[i] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {

            int v = edge[i].to;
            // printf("%d\n", v);
            ind[v]--;
            (f[v] += f[u]) %= P;
            if (ind[v] == 0)
                Q.push(v);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        ind[v]++, oud[u]++;
    }
    topo_sort();
    for (int i = 1; i <= n; i++)
        if (oud[i] == 0)
            (ans += f[i]) %= P;
    printf("%lld", ans);
    return 0;
}