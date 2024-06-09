#include <memory.h>
#include <stdio.h>

const int N = 1e3 + 5;
const int M = 1e6 + 5;

int n, m, e, ans;
int num_edge, head[N];
int match[N];
bool used[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

bool dfs(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!used[v])
        {
            used[v] = true;
            if (!match[v] or dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (v > m or u > n)
            continue;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof used);
        if (dfs(i))
            ans++;
    }
    printf("%d", ans);
    return 0;
}