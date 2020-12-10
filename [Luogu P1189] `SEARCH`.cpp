#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <queue>

const int N = 1e2 + 5;
const int M = 2e3 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, opt;
char map[N][N];
bool foo[N][N][M];
int dir[M];

void dfs(int depth, int x, int y, bool flag)
{
    if (x < 1 or y < 1 or x > n or y > m or depth > opt or foo[x][y][depth] or map[x][y] == 'X')
        return;
    if (depth == opt)
        map[x][y] = '*';
    dfs(depth, x + dx[dir[depth]], y + dy[dir[depth]], true);
    if (flag)
        dfs(depth + 1, x + dx[dir[depth + 1]], y + dy[dir[depth + 1]], true);
    foo[x][y][depth] = true;
}

int main()
{
    int x, y;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == '*')
                x = i, y = j, map[i][j] = '.';
        }

    std::cin >> opt;
    for (int i = 1; i <= opt; i++)
    {
        std::string str;
        std::cin >> str;
        if (str[0] == 'N')
            dir[i] = 0;
        else if (str[0] == 'S')
            dir[i] = 1;
        else if (str[0] == 'W')
            dir[i] = 2;
        else
            dir[i] = 3;
    }
    dfs(1, x, y, false);
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            std::cout << map[i][j];
    return 0;
}