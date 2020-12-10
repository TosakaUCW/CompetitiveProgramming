#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 5e2 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, stx, sty, cnt;
int map[N][N];
bool vis[N][N], site[N][N];

struct Node
{
    int x, y;
};

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

bool judge(int d)
{
    memset(vis, false, sizeof vis);
    int res = 1;
    std::queue<Node> Q;
    Q.push(Node{stx, sty});
    vis[stx][sty] = true;
    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 or xx > n or yy < 1 or yy > m or abs(map[xx][yy] - map[x][y]) > d or vis[xx][yy])
                continue;
            if (site[xx][yy])
                res++;
            vis[xx][yy] = true;
            Q.push(Node{xx, yy});
        }
    }
    return res == cnt;
}

int main()
{
    int L = 0, R = 0, res = 0;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            map[i][j] = read(), R = std::max(R, map[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            site[i][j] = read();
            if (site[i][j])
                stx = i, sty = j, cnt++;
        }

    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d", res);
    return 0;
}