#include <math.h>
#include <memory.h>
#include <stdio.h>

const int N = 1e3 + 5;
const int M = 1e6 + 5;

int n, m, t, ans;
double x[N], y[N];
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

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= m; i++)
        scanf("%lf%lf", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
    {
        double a, b, v;
        scanf("%lf%lf%lf", &a, &b, &v);
        for (int j = 1; j <= m; j++)
            if (t * v >= dis(a, b, x[j], y[j]))
                add_edge(i, j);
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