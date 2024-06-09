#include <stdio.h>
#include <string>
#include <iostream>

std::string s;

const int N = 4 + 5;
int n = 4;
int a[N][N];
bool flag;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool judge(int res = 0)
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            res += a[i][j];
    return res == 0 or res == 16;
}

void reverse(int x, int y)
{
    a[x][y] ^= 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1 <= nx and nx <= 4 and 1 <= ny and ny <= 4)
            a[nx][ny] ^= 1;
    }
}

void dfs(int x, int y, int res, int lim)
{
    if (res == lim)
        return flag |= judge(), void();
    if (flag or y == 5)
        return;

    reverse(x, y);
    if (x + 1 <= 4)
        dfs(x + 1, y, res + 1, lim);
    else
        dfs(1, y + 1, res + 1, lim);
    reverse(x, y);
    if (x + 1 <= 4)
        dfs(x + 1, y, res, lim);
    else
        dfs(1, y + 1, res, lim);
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        std::cin >> s;
        for (int j = 0; j < 4; j++)
            a[i][j + 1] = s[j] == 'b';
    }
    for (int i = 0; i <= 16; i++)
    {
        dfs(1, 1, 0, i);
        if (flag)
            return printf("%d", i), 0;
    }
    return puts("Impossible"), 0;
}