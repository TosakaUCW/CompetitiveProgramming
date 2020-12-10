#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;
const int M = 1e5;

int n, m, ans, num_edge;
int color[N + 5], vis[N + 5], head[N + 5];
std::queue<int> q;

struct Node
{
    int to, next;
} edge[2 * M + 5];

void add_edge(int u, int v)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void bfs(int start)
{
    if (vis[start])
        return;
    vis[start] = true;
    color[start] = 1;
    int black = 1, white = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (color[u] == color[v])
            {
                printf("Impossible");
                exit(0);
            }
            if (!vis[v])
            {
                q.push(v);
                color[v] = -color[u];
                if (color[v] == 1)
                    black++;
                else
                    white++;
            }
        }
    }
    ans += std::min(black, white);
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    Rep(i, 1, n)
        bfs(i);
    printf("%d", ans);
    return 0;
}