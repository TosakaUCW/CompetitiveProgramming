#include <stdio.h>
#include <algorithm>

const int N = 4e5 + 5;

int n, m;
int ans[N], depth[N];
int st[N], tail;
int head[N], num_edge;

struct Node
{
    int next, to;
} edge[N];

struct Seg
{
    int l, r, id;
    bool friend operator<(Seg a, Seg b) { return a.l < b.l; }
} a[N];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void dfs(int cur, int fa, int front)
{
    depth[cur] = depth[fa] + 1;
    st[++tail] = cur;
    if (a[cur].id != 0)
    {
        while (front < tail and a[cur].l + m <= a[st[front + 1]].r)
            front++;
        ans[a[cur].id] = depth[cur] - depth[st[front]] + 1;
    }
    for (int i = head[cur]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        dfs(to, cur, front);
    }
    tail--;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r)
            r += m;
        a[i].l = l, a[i].r = r, a[i].id = i;
        a[i + n].l = l + m, a[i + n].r = r + m;
    }
    std::sort(a + 1, a + 1 + 2 * n);
    int p = 1;
    for (int i = 1; i < 2 * n; i++)
    {
        while (p < 2 * n and a[p + 1].l <= a[i].r)
            p++;
        add_edge(p, i);
    }
    dfs(2 * n, 0, 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}