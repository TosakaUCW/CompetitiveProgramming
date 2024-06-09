#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = 10 + 5;

int n, cnt;
char map[M][N];
bool f[M][N], vis[N];

void print(int x, int y)
{
    if (x == 10 and f[x][y - 1])
        print(x, y - 1);
    else if (x == 10 and f[x - 1][y - 1])
        print(x - 1, y - 1);
    else if (x == 1 and f[x][y - 1])
        vis[y - 1] = true, print(x, y - 1);
    else if (x == 1 and f[x + 1][y - 1])
        vis[y - 1] = true, print(x + 1, y - 1);
    else if (f[x - 1][y - 1])
        print(x - 1, y - 1);
    else if (f[x + 1][y - 1])
        vis[y - 1] = true, print(x + 1, y - 1);
}

void go(int opt)
{
    for (int i = 1, p; i <= n; i = p + 1)
    {
        for (p = i; vis[p]; p++)
            ;
        if (vis[i] and !opt)
            cnt++;
        else if (vis[i])
            printf("%d %d\n", i - 1, p - i);
    }
}

int main()
{
    n = read();
    for (int i = 1; i <= 10; i++)
        scanf("%s", map[i] + 1);
    if (map[10][1] == '.')
        f[10][1] = true;
    for (int j = 2; j <= n; j++)
        for (int i = 1; i <= 10; i++)
            if (map[i][j] == '.')
                if (i == 1)
                    f[i][j] |= f[i][j - 1], f[i][j] |= f[i + 1][j - 1];
                else if (i == 10)
                    f[i][j] |= f[i][j - 1], f[i][j] |= f[i - 1][j - 1];
                else
                    f[i][j] |= f[i - 1][j - 1], f[i][j] |= f[i + 1][j - 1];
    for (int i = 1; i <= 10; i++)
        if (f[i][n])
        {
            print(i, n);
            break;
        }
    go(0), printf("%d\n", cnt), go(1);
    return 0;
}