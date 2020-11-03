#include <stdio.h>
#include <iostream>

const int N = 2e3 + 5;

int n, m, e, q;
int ans, k;
int fa[4][N][N];
bool dead[N][N];

struct Node
{
    int x, y;
} a[N << 3];

int find1(int x, int y) { return fa[0][x][y] == x ? x : fa[0][x][y] = find1(fa[0][x][y], y); }
int find2(int x, int y) { return fa[1][x][y] == x ? x : fa[1][x][y] = find2(fa[1][x][y], y); }
int find3(int x, int y) { return fa[2][x][y] == y ? y : fa[2][x][y] = find3(x, fa[2][x][y]); }
int find4(int x, int y) { return fa[3][x][y] == y ? y : fa[3][x][y] = find4(x, fa[3][x][y]); }

void remove(int x, int y)
{
    if (dead[x][y])
        return;
    dead[x][y] = true, ans++;
    fa[0][x][y]--, fa[1][x][y]++, fa[2][x][y]--, fa[3][x][y]++;
}

void up()
{
    for (int i = 1; i <= e; i++)
    {
        int x = a[i].x, y = a[i].y;
        a[i].x -= k;
        if (y < 1 or y > m or x < 1)
            continue;
        if (x > n)
            x = n;
        while ((x = find1(x, y)) >= 1 and x >= a[i].x)
            remove(x, y);
    }
}

void down()
{
    for (int i = 1; i <= e; i++)
    {
        int x = a[i].x, y = a[i].y;
        a[i].x += k;
        if (y < 1 or y > m or x > n)
            continue;
        if (x < 1)
            x = 1;
        while ((x = find2(x, y)) <= n and x <= a[i].x)
            remove(x, y);
    }
}

void left()
{
    for (int i = 1; i <= e; i++)
    {
        int x = a[i].x, y = a[i].y;
        a[i].y -= k;
        if (x < 1 or x > n or y < 1)
            continue;
        if (y > m)
            y = m;
        while ((y = find3(x, y)) >= 1 and y >= a[i].y)
            remove(x, y);
    }
}

void right()
{
    for (int i = 1; i <= e; i++)
    {
        int x = a[i].x, y = a[i].y;
        a[i].y += k;
        if (x < 1 or x > n or y > m)
            continue;
        if (y < 1)
            y = 1;
        while ((y = find4(x, y)) <= m and y <= a[i].y)
            remove(x, y);
    }
}

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

int main()
{
    n = read(), m = read(), e = read(), q = read();
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            fa[0][i][j] = fa[1][i][j] = i,
            fa[2][i][j] = fa[3][i][j] = j;
    for (int i = 1; i <= e; i++)
        a[i].x = read(), a[i].y = read(), remove(a[i].x, a[i].y);
    for (int i = 1; i <= n; i++)
        a[++e].x = i, a[e].y = 0,
        a[++e].x = i, a[e].y = m + 1;
    for (int i = 1; i <= m; i++)
        a[++e].x = 0, a[e].y = i,
        a[++e].x = n + 1, a[e].y = i;
    while (q--)
    {
        ans = 0;
        char ch;
        std::cin >> ch >> k;
        if (ch == 'U')
            down();
        if (ch == 'D')
            up();
        if (ch == 'R')
            left();
        if (ch == 'L')
            right();
        printf("%d\n", ans);
    }
    return 0;
}