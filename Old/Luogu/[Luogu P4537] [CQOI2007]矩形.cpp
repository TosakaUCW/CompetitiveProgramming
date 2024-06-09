#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 10 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, ans;
bool vis[N][N];

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

void dfs(int x, int y)
{
    if (x < 1 or x >= n or y < 1 or y >= m)
    {
        ans++;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
        if (!vis[x + dx[i]][y + dy[i]])
            dfs(x + dx[i], y + dy[i]);
    vis[x][y] = false;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
        memset(vis, 0, sizeof vis), vis[i][0] = 1, dfs(i, 1);
    for (int i = 1; i < m; i++)
        memset(vis, 0, sizeof vis), vis[0][i] = 1, dfs(1, i);
    printf("%d", ans);
    return 0;
}