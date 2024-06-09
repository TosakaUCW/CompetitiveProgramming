#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e2 + 5;
const int M = 4e4 + 5;

int n, m, q;
int t[N], dis[N][N];

int main()
{
    memset(dis, 0x3f, sizeof dis);
    memset(t, 0x3f, sizeof t);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]), dis[i][i] = 0;
    for (int i = 1, u, v, dist; i <= m; i++)
        scanf("%d%d%d", &u, &v, &dist), dis[u][v] = dis[v][u] = dist;
    scanf("%d", &q);
    for (int u, v, time, k = 0; q; q--)
    {
        scanf("%d%d%d", &u, &v, &time);
        for (; t[k] <= time; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
        if (dis[u][v] == 0x3f3f3f3f or t[u] > time or t[v] > time)
            puts("-1");
        else
            printf("%d\n", dis[u][v]);
    }
    return 0;
}