// luogu-judger-enable-o2
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;

int n, m, ans[10000005];
int num_edge, head[N + 5];
int tot, sum, root;
int size[N + 5], dis[N + 5], f[N + 5];
bool vis[N + 5];

struct Node
{
    int next, to, dis;
} edge[2 * N + 5];

void add_edge(int u, int v, int dis)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
    head[u] = num_edge;
}

void find_root(int u, int fa)
{
    f[u] = 0;
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v] or v == fa)
            continue;
        find_root(v, u);
        size[u] += size[v];
        f[u] = std::max(f[u], size[v]);
    }
    f[u] = std::max(f[u], sum - size[u]);
    if (f[u] < f[root])
        root = u;
}

void find_dep(int u, int fa, int l)
{
    dis[++tot] = l;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v] or v == fa)
            continue;
        find_dep(v, u, l + edge[i].dis);
    }
}

void calc(int u, int l, int c)
{
    tot = 0;
    find_dep(u, 0, l);
    Rep(i, 1, tot)
        Rep(j, 1, tot)
            ans[dis[i] + dis[j]] += c;
}

void devide(int u)
{
    vis[u] = true;
    calc(u, 0, 1);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v])
            continue;
        calc(v, edge[i].dis, -1);
        root = 0, sum = size[v];
        find_root(v, 0);
        devide(root);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n - 1)
    {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        add_edge(u, v, dis);
        add_edge(v, u, dis);
    }
    sum = f[0] = n;
    find_root(1, 0);
    devide(root);
    Rep(i, 1, m)
    {
        int k;
        scanf("%d", &k);
        if (ans[k])
            printf("AYE\n");
        else
            printf("NAY\n");
    }
    return 0;
}