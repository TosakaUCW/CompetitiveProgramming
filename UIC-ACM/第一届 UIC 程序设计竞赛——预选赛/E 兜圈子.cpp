#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e2 + 5;
int n, m;
char map[N][N];
bool vis[N][N];
void dfs(int i, int j)
{
    if (vis[i][j]) return puts("-1"), exit(0);
    vis[i][j] = 1;
    int x = i, y = j;
    if (map[i][j] == 'R') y++;
    if (map[i][j] == 'L') y--;
    if (map[i][j] == 'D') x++;
    if (map[i][j] == 'U') x--;
    if (x < 1 or x > n or y < 1 or y > m)
        return printf("%d %d", i, j), void();
    dfs(x, y);
}
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++, getchar())
        for (int j = 1; j <= m; j++)
            scanf("%c", &map[i][j]);
    // for (int i = 1; i <= n; i++, puts(""))
    //     for (int j = 1; j <= m; j++)
    //         printf("%c", map[i][j]);
    dfs(1, 1);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}