#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 500;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, ans;
int map[N + 5][N + 5], l[N + 5][N + 5], r[N + 5][N + 5];
bool vis[N + 5][N + 5], flag;

void dfs(int x, int y)
{
    vis[x][y] = true;
    Rep(i, 0, 3)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 or ny < 1 or nx > n or ny > m)
            continue;
        if (map[nx][ny] >= map[x][y])
            continue;
        if (!vis[nx][ny])
            dfs(nx, ny);
        l[x][y] = std::min(l[x][y], l[nx][ny]);
        r[x][y] = std::max(r[x][y], r[nx][ny]);
    }
}

void get_answer()
{
    int left = 1;
    while (left <= m)
    {
        int right = 0;
        Rep(i, 1, m) if (l[1][i] <= left)
            right = std::max(right, r[1][i]);
        ans++;
        left = right + 1;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
        Rep(j, 1, m)
            scanf("%d", &map[i][j]);
    memset(l, 127, sizeof(l));
    Rep(i, 1, m)
        l[n][i] = r[n][i] = i;
    Rep(i, 1, m)
        dfs(1, i);
    Rep(i, 1, m) if (!vis[n][i])
    {
        ans++;
        flag = true;
    }
    if (flag)
    {
        printf("0\n%d", ans);
        return 0;
    }
    get_answer();
    printf("1\n%d", ans);
    return 0;
}