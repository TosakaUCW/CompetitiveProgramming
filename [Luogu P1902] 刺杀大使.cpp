#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, ans;
int map[N][N];
bool vis[N][N], flag;

void dfs(int x, int y, int max)
{

    vis[x][y] = true;
    if (x == n)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (map[xx][yy] > max or x < 1 or x > n or y < 1 or y > m or vis[xx][yy])
            continue;
        dfs(xx, yy, max);
        if (flag)
            return;
    }
}

bool judge(int x)
{
    memset(vis, 0, sizeof vis);
    flag = false;
    dfs(1, 1, x);
    return flag;
}

int main()
{
    freopen("murder.in", "r", stdin);
    freopen("murder.out", "w", stdout);
    int L = 0, R = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]), R = std::max(R, map[i][j]);
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d", ans);
    return 0;
}
/*
4 2
0 0
3 5
2 4
0 0

3
*/