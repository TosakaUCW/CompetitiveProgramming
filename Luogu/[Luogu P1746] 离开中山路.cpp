#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>

const int N = 1e3 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, x1, y1, x2, y2;
char map[N][N];
bool vis[N][N];

struct Node
{
    int x, y, dis;
};

std::queue<int> Qx, Qy, Qdis;

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

void bfs()
{
    Qx.push(x1);
    Qy.push(y1);
    Qdis.push(0);
    while (!Qx.empty())
    {
        int x = Qx.front();
        int y = Qy.front();
        int dis = Qdis.front();
        Qx.pop(), Qy.pop(), Qdis.pop();
        if (x == x2 and y == y2)
        {
            printf("%d", dis);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (vis[xx][yy] or x < 1 or n < x or y < 1 or n < y or map[xx][yy] == '1')
                continue;
            vis[xx][yy] = true;
            Qx.push(xx), Qy.push(yy), Qdis.push(dis + 1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P1746_1.in", "r", stdin);
#endif // !ONLINE_JUDGE
    // n = read();
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> map[i][j];
    // x1 = read(), y1 = read(), x2 = read(), y2 = read();
    std::cin >> x1 >> y1 >> x2 >> y2;
    bfs();
    return 0;
}