#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 10;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int ans, vis[N + 5][N + 5][N + 5][N + 5];
char map[N + 5][N + 5];
struct Node
{
    int x, y, dir;
} fam, cow;

void move(Node &a)
{
    int xx = a.x + dx[a.dir];
    int yy = a.y + dy[a.dir];
    if (map[xx][yy] != '*')
        a.x = xx, a.y = yy;
    else
    {
        a.dir++;
        a.dir %= 4;
    }
}

int main()
{
    std::fill(map[0], map[0] + 12, '*');
    std::fill(map[11], map[11] + 12, '*');
    Rep(i, 1, 10)
    {
        scanf("%s\n", &map[i][1]);
        map[i][0] = map[i][11] = '*';
        Rep(j, 1, 10)
        {
            if (map[i][j] == 'C')
                cow = (Node){i, j, 0};
            if (map[i][j] == 'F')
                fam = (Node){i, j, 0};
        }
    }
    while (fam.x != cow.x or fam.y != cow.y)
    {
        if (vis[fam.x][fam.y][cow.x][cow.y]++ == 4)
        {
            printf("0");
            return 0;
        }
        ans++;
        move(cow), move(fam);
    }
    printf("%d", ans);
    return 0;
}