#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int INF = 2147483647;

int n, m, k;
int head[N], num_edge;
int fath[N];
int fa[N][25], dis[N][25];
int depth[N];
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[M];
struct node
{
    int u, v, dis;
    // bool friend operator<(node a, node b) { return a.dis > b.dis; }
} Edge[M];

bool cmp(node a, node b) { return a.dis > b.dis; }

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

int find(int x) { return x == fath[x] ? x : fath[x] = find(fath[x]); }

void Kruscal()
{
    std::sort(Edge + 1, Edge + 1 + n, cmp);
    for (int i = 1; i <= m; i++)
        fath[i] = i;
    for (int i = 1; i <= n; i++)
        if (find(Edge[i].u) != find(Edge[i].v))
        {
            fath[find(Edge[i].u)] = find(Edge[i].v);
            add_edge(Edge[i].u, Edge[i].v, Edge[i].dis);
            add_edge(Edge[i].v, Edge[i].u, Edge[i].dis);
        }
}

void dfs(int cur)
{
    vis[cur] = true;
    for (int i = head[cur]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v])
            continue;
        fa[v][0] = cur;
        depth[v] = depth[cur] + 1;
        dis[v][0] = edge[i].dis;
        dfs(v);
    }
}

int lca(int x, int y)
{
    if (find(x) != find(y))
        return -1;
    int ans = INF;
    if (depth[x] > depth[y])
        std::swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (depth[fa[y][i]] >= depth[x])
        {
            ans = std::min(ans, dis[y][i]);
            y = fa[y][i];
        }
    if (x == y)
        return ans;
    for (int i = 20; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
        {
            ans = std::min(ans, std::min(dis[x][i], dis[y][i]));
            x = fa[x][i], y = fa[y][i];
        }
    ans = std::min(ans, std::min(dis[x][0], dis[y][0]));
    return ans;
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1, u, v, dis; i <= n; i++)
    {
        scanf("%d%d%d", &u, &v, &dis);
        Edge[i] = node{u, v, dis};
    }
    Kruscal();
    for (int i = 1; i <= m; i++)
        if (!vis[i])
            depth[i] = 1, dfs(i), fa[i][0] = i, dis[i][0] = INF;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= m; j++)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            dis[j][i] = std::min(dis[j][i - 1], dis[fa[j][i - 1]][i - 1]);
        }
    scanf("%d", &k);
    for (int u, v; k; k--)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}