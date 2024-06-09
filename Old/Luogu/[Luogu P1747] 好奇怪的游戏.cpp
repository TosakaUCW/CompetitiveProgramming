#include <stdio.h>
#include <algorithm>
#include <queue>
#include <memory.h>

const int N = 20 + 5;
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 2, -2, 2, -2, 1, -1, 1, -1};

int x1, x2, y1, y2;
bool vis[N][N];

struct Node
{
    int x, y, val;
};

int bfs(int x, int y)
{
    memset(vis, 0, sizeof vis);
    std::queue<Node> Q;
    while (!Q.empty())
        Q.pop();
    Q.push({x, y, 0}), vis[x][y] = true;
    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int val = Q.front().val;
        Q.pop();
        for (int i = 0; i < 12; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx == 1 and yy == 1)
                return val + 1;
            if (!vis[xx][yy] and 1 < xx and 1 < yy)
                Q.push({xx, yy, val + 1}), vis[xx][yy] = true;
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n%d", bfs(x1, y1), bfs(x2, y2));
    return 0;
}