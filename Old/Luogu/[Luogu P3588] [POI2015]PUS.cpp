#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>

const int N = 8e5 + 5;
const int M = N << 1;
const int INF = 1e9;

int n, s, m;
int rt, node_cnt;
int ls[N], rs[N], ind[N], f[N], d[N];
int head[N], num_edge;
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge, ind[v]++; }

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

void build(int &p, int l, int r)
{
    if (l == r)
    {
        p = l;
        return;
    }
    p = ++node_cnt;
    int mid = (l + r) >> 1;
    build(ls[p], l, mid), build(rs[p], mid + 1, r);
    add_edge(ls[p], p, 0), add_edge(rs[p], p, 0);
}

void update(int p, int l, int r, int x, int y, int v)
{
    if (x <= l and r <= y)
    {
        add_edge(p, v, 0);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(ls[p], l, mid, x, y, v);
    if (mid < y)
        update(rs[p], mid + 1, r, x, y, v);
}

void topo_sort()
{
    std::queue<int> Q;
    for (int i = 1; i <= node_cnt; i++)
    {
        if (!d[i])
            d[i] = 1;
        if (!ind[i])
            Q.push(i);
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(), vis[u] = true;
        for (int i = head[u], v; i; i = edge[i].next)
        {
            v = edge[i].to;
            d[v] = std::max(d[v], d[u] + edge[i].dis);
            if (f[v] and d[v] > f[v])
            {
                puts("NIE");
                exit(0);
            }
            if (!--ind[v])
                Q.push(v);
        }
    }
}

int main()
{
    node_cnt = n = read(), s = read(), m = read(), build(rt, 1, n);
    for (int i = 1, pos; i <= s; i++)
        pos = read(), d[pos] = f[pos] = read();
    for (int i = 1, l, r, k; i <= m; i++)
    {
        l = read(), r = read(), k = read();
        int pre = l - 1, now = 0;
        ++node_cnt;
        while (k--)
        {
            now = read();
            add_edge(node_cnt, now, 1);
            if (now > pre + 1)
                update(rt, 1, n, pre + 1, now - 1, node_cnt);
            pre = now;
        }
        if (now < r)
            update(rt, 1, n, now + 1, r, node_cnt);
    }
    topo_sort();
    for (int i = 1; i <= node_cnt; i++)
        if (!vis[i] or d[i] > INF)
        {
            puts("NIE");
            return 0;
        }
    puts("TAK");
    for (int i = 1; i <= n; i++)
        printf("%d ", d[i]);
    return 0;
}