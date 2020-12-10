#include <stdio.h>
#include <queue>

const int N = 30 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n;
int map[N][N];
bool vis[N][N];

struct Node
{
    int x, y;
};

void bfs(int x, int y)
{
    std::queue<Node> Q, P;
    Q.push({x, y}), vis[x][y] = true;
    while (!Q.empty())
    {
        int x = Q.front().x, y = Q.front().y;
        P.push(Q.front()), Q.pop();
        map[x][y] = 2;
        // printf("%d%d\n", x, y);
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (!vis[xx][yy] and map[xx][yy] == 0 and 1 <= xx and xx <= n and 1 <= yy and yy <= n)
                vis[xx][yy] = true, Q.push({xx, yy});
        }
    }
}

void go()
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (map[i][j] == 1)
            {
                bfs(i + 1, j + 1);
                return;
            }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                vis[i][j] = true;
        }
    go();
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            printf("%d ", map[i][j]);
    return 0;
}