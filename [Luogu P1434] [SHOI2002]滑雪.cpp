#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, ans;
int map[N][N];
int vis[N][N];

int dfs(int x, int y)
{
    if (vis[x][y])
        return vis[x][y];
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 and xx <= n and yy >= 1 and yy <= n and map[x][y] > map[xx][yy])
            dfs(xx, yy), vis[x][y] = std::max(vis[x][y], vis[xx][yy] + 1);
    }
    return vis[x][y];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = std::max(ans, dfs(i, j));
    printf("%d", ans);
    return 0;
}