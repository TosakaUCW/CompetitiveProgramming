#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 200 + 5;
const int dx[] = {-1, -1, -1};
const int dy[] = {-1, 0, 1};

int n, m;
int a[N][N];
int f[N][N];

void read(int &n)
{
    char c = '+';
    int x = 0;
    bool flag = 0;
    while (c < '0' || c > '9')
    {
        c = getchar();
        if (c == '-')
            flag = 1;
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - 48);
        c = getchar();
    }
    flag == 1 ? n = -x : n = x;
}

int dfs(int x, int y)
{
    if (x == 1)
        return f[x][y] == f[0][0] ? (f[x][y] = a[x][y]) : f[x][y];
    if (f[x][y] != f[0][0])
        return f[x][y];
    for (int i = 0; i < 3; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (1 <= xx and xx <= m and 1 <= yy and yy <= n)
            f[x][y] = std::max(f[x][y], dfs(xx, yy) + a[x][y]);
    }
    return f[x][y];
}

int main()
{
    memset(f, 0xcf, sizeof f);
    read(m), read(n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            read(a[i][j]);
    printf("%d", dfs(m + 1, n / 2 + 1));
    return 0;
}