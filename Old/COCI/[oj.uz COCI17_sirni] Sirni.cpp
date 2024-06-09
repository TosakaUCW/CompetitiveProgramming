#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = 1e7 + 5;
const int INF = 2147483647;

int n;
int a[N];
int head[N], num_edge;
int dis[N];
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

int prim()
{
    int now = 1, tot = 0, ans = 0;
    for (int i = 2; i <= n; ++i)
        dis[i] = INF;
    for (int i = head[1]; i; i = edge[i].next)
        dis[edge[i].to] = std::min(dis[edge[i].to], edge[i].dis);
    while (++tot < n)
    {
        int minn = INF;
        vis[now] = 1;
        for (int i = 1; i <= n; ++i)
            if (!vis[i] and minn > dis[i])
            {
                minn = dis[i];
                now = i;
            }
        ans += minn;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > edge[i].dis and !vis[v])
                dis[v] = edge[i].dis;
        }
    }
    return ans;
}

int main()
{
    freopen("sirni.in", "r", stdin), freopen("sirni.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i ^ j)
                add_edge(i, j, std::min(a[i] % a[j], a[j] % a[i]));
    return printf("%d", prim()), 0;
}