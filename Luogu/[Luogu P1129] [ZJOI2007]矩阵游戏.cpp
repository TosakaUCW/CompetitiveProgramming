#include <memory.h>
#include <stdio.h>

const int N = 1e6 + 5;
const int M = 2e6 + 5;

int n, ans;
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        memset(head, 0, sizeof head);
        memset(match, 0, sizeof match);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int x;
                scanf("%d", &x);
                if (x)
                    add_edge(i, j + n);
            }
        for (int i = 1; i <= n; i++)
        {
            memset(used, false, sizeof used);
            if (dfs(i))
                ans++;
        }
        if (ans == n)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}