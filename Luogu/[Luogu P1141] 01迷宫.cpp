#include <stdio.h>
#include <iostream>
#include <queue>

const int N = 1e3 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m;
char map[N][N];
int ans[N][N];
bool vis[N][N];

struct Node
{
  int x, y;
};

void bfs(int xxx, int yyy)
{
  int cnt = 1;
  std::queue<Node> Q, P;
  Q.push({xxx, yyy}), vis[xxx][yyy] = true;
  while (!Q.empty())
  {
    int x = Q.front().x, y = Q.front().y;
    P.push(Q.front()), Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int xx = x + dx[i], yy = y + dy[i];
      if (!vis[xx][yy] and map[xx][yy] != map[x][y] and 1 <= xx and xx <= n and 1 <= yy and yy <= n)
        vis[xx][yy] = true, Q.push({xx, yy}), cnt++;
    }
  }
  while (!P.empty())
    ans[P.front().x][P.front().y] = cnt, P.pop();
}

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      std::cin >> map[i][j];
  while (m--)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    if (ans[x][y] == 0)
      bfs(x, y);
    printf("%d\n", ans[x][y]);
  }
  return 0;
}