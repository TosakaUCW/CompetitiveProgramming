#include <memory.h>
#include <stdio.h>

const int N = 1e4 + 5;
const int M = 5e4 + 5;
const int x[4] = {0, 0, 1, -1};
const int y[4] = {-1, 1, 0, 0};

int n, m, ans;
int num_edge, head[N];
int match[N];
bool used[N], map[N][N];

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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!map[i][j])
                for (int k = 0; k <= 3; k++)
                {
                    int dx = i + x[k];
                    int dy = j + y[k];
                    if (dx < 1 or dy < 1 or dx > n or dy > n)
                        continue;
                    if (!map[dx][dy])
                        add_edge(n * (i - 1) + j, n * (dx - 1) + dy);
                }
    for (int i = 1; i <= n * n; i++)
    {
        memset(used, false, sizeof used);
        if (dfs(i))
            ans++;
    }
    printf("%d", ans / 2);
    return 0;
}