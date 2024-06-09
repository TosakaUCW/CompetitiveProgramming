#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e3 + 5;
const int M = N * N;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, ans[M];
bool map[N][N], vis[N][N];

struct Node
{
    int x, y, dis;
};

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

void bfs(int sx, int sy, int res = 1)
{
    std::queue<Node> Q;
    Q.push(Node{sx, sy, 1}), vis[sx][sy] = true;
    for (int x, y, dis; !Q.empty();)
    {
        x = Q.front().x, y = Q.front().y, dis = Q.front().dis, Q.pop();
        for (int i = 0, nx, ny; i < 4; i++)
            if (!vis[nx = x + dx[i]][ny = y + dy[i]] and nx >= 1 and ny >= 1 and nx <= n and ny <= n and map[nx][ny])
                res = std::max(res, dis + 1), vis[nx][ny] = true, Q.push(Node{nx, ny, dis + 1});
    }
    ans[++ans[0]] = res;
}

int main()
{
    freopen("graph.in", "r", stdin), freopen("graph.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        char ch[N];
        scanf("%s", ch + 1);
        for (int j = 1; j <= n; j++)
            map[i][j] = ch[j] == '1';
    }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
            if (map[i][j] and !vis[i][j])
                bfs(i, j);
    printf("%d\n", ans[0]), std::sort(ans + 1, ans + 1 + ans[0]);
    for (int i = 1; i <= ans[0]; i++)
        printf("%d\n", ans[i]);
    return 0;
}