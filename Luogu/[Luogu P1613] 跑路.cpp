#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 60 + 5;

int n, m;
int dis[N][N];
int graph[N][N][N];

int main()
{
    memset(dis, 0x3f, sizeof dis);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        dis[u][v] = 1;
        graph[u][v][0] = true;
    }
    for (int k = 1; k <= 65; k++)
        for (int u = 1; u <= n; u++)
            for (int t = 1; t <= n; t++)
                for (int v = 1; v <= n; v++)
                    if (graph[u][t][k - 1] and graph[t][v][k - 1])
                    {
                        dis[u][v] = 1;
                        graph[u][v][k] = true;
                    }
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                dis[u][v] = std::min(dis[u][v], dis[u][k] + dis[k][v]);
    printf("%d", dis[1][n]);
    return 0;
}