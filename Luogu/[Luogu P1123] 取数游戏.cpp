#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 6 + 5;
const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m, ans;
int map[N][N];
bool vis[N][N];

void dfs(int x, int y, int val)
{
    int xx = x;
    int yy = y + 1;
    if (x > n)
    {
        ans = std::max(ans, val);
        return;
    }
    if (yy > m)
        xx++, yy = 1;
    bool flag = false;
    for (int i = 0; i < 8; i++)
        flag |= vis[x + dx[i]][y + dy[i]];
    if (!flag)
        vis[x][y] = true, dfs(xx, yy, val + map[x][y]), vis[x][y] = false;
    dfs(xx, yy, val);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        memset(vis, 0, sizeof vis);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        dfs(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}