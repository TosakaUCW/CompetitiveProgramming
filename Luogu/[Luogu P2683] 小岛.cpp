#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int INF = 715827882;

int n, m;
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                f[i][j] = INF;
    while (m--)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", f[u][v] == INF ? -1 : f[u][v]);
        }
        else if (opt == 1)
        {
            int u, v, dis;
            scanf("%d%d%d", &u, &v, &dis);
            f[u][v] = f[v][u] = std::min(f[u][v], dis);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[i][j] = f[j][i] = std::min(f[i][j], f[i][u] + f[u][v] + f[v][j]);
        }
    }
    return 0;
}