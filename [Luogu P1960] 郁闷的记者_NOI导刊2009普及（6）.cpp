#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e3;
const int M = 1e5;
int n, m, num_edge, head[N + 5];
int rank[N + 5], ind[N + 5];
int h, t, queue[4 * M + 5];
bool flag;
struct Edge
{
    int next, to;
} edge[M + 5];
struct Node
{
    int u, rank;
} ans[N + 5];

void add_edge(int from, int to)
{
    num_edge++;
    edge[num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}

inline void push(int x)
{
    queue[++t] = x;
}

void topo_sort()
{
    h = 1, t = 0;
    Rep(i, 1, n) if (!ind[i])
        push(i);
    while (h <= t)
    {
        int u = queue[h];
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            ind[v]--;
            rank[v] = rank[u] + 1;
            if (!ind[v])
                push(v);
        }
        h++;
    }
}

inline bool cmp(Node a, Node b)
{
    return a.rank < b.rank;
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, m)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        add_edge(from, to);
        ind[to]++;
    }
    topo_sort();
    Rep(i, 1, n)
    {
        ans[i].u = i;
        ans[i].rank = rank[i];
    }
    std::sort(ans + 1, ans + 1 + n, cmp);
    Rep(i, 1, n)
    {
        printf("%d\n", ans[i].u);
        if (ans[i].rank == ans[i + 1].rank)
            flag = true;
    }
    printf("%d", flag);
    return 0;
}