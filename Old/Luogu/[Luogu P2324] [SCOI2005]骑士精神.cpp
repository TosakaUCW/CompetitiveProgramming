#include <bits/stdc++.h>
using namespace std;
long long T, mp[7][7], sx, sy;
long long finish[7][7] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0, 2, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}};
const long long wx[] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const long long wy[] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
long long nx, ny;
bool flag;
char pd;
long long Astar()
{
    long long cnt = 0;
    for (long long i = 1; i <= 5; i++)
    {
        for (long long j = 1; j <= 5; j++)
        {
            if (mp[i][j] != finish[i][j])
                cnt++;
        }
    }
    return cnt;
}
void dfs(long long x, long long y, long long depth, long long Maxdepth)
{
    //	printf("%lld %lld\n",x,y);
    //	getchar();
    if (depth == Maxdepth)
    {
        if (!Astar())
            flag = 1;
        return;
    }
    for (long long i = 1; i <= 8; i++)
    {
        long long nx = x + wx[i], ny = y + wy[i];
        if (nx < 1 || nx > 5 || ny < 1 || ny > 5)
            continue;
        swap(mp[x][y], mp[nx][ny]);
        long long tmp = Astar();
        if (depth + tmp <= Maxdepth)
            dfs(nx, ny, depth + 1, Maxdepth);
        swap(mp[x][y], mp[nx][ny]);
    }
}
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        flag = 0;
        for (long long i = 1; i <= 5; i++)
        {
            for (long long j = 1; j <= 5; j++)
            {
                cin >> pd;
                if (pd == '*')
                    mp[i][j] = 2, sx = i, sy = j;
                else
                    mp[i][j] = pd - '0';
            }
        }
        if (!Astar())
        {
            printf("0\n");
            continue;
        }
        for (long long i = 1; i <= 15; i++)
        {
            dfs(sx, sy, 0, i);
            if (flag)
            {
                printf("%lld\n", i);
                break;
            }
        }
        if (!flag)
            printf("-1\n");
    }
    return 0;
}
