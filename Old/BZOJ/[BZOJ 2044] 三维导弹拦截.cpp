#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int M = 1e6 + 5;

int n, ans_1, ans_2;
int f[N];
int num_edge, head[N];
int match[N];
bool used[N];

struct Node
{
    int next, to;
} edge[M];

struct Pos
{
    int x, y, z;
    bool friend operator<(Pos a, Pos b) { return a.x < b.x; }
    bool friend operator>(Pos a, Pos b) { return a.x > b.x and a.y > b.y and a.z > b.z; }
} a[N];

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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= i - 1; j++)
            if (a[i] > a[j])
                f[i] = std::max(f[i], f[j] + 1), add_edge(j, i);
        ans_1 = std::max(ans_1, f[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof used);
        if (dfs(i))
            ans_2++;
    }
    printf("%d\n%d", ans_1, n - ans_2);
    return 0;
}