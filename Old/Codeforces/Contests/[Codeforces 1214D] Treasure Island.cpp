#include <stdio.h>
#include <string>
#include <iostream>

const int N = 1e6 + 5;

int n, m;
std::string map[N];

bool dfs(int x, int y)
{
    if (x == n and y == m)
        return true;
    if (x > n or y > m)
        return false;
    if (map[x][y] == '#')
        return false;
    if (x != 1 or y != 1)
        map[x][y] = '#';
    return dfs(x + 1, y) or dfs(x, y + 1);
}

int main()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> map[i], map[i] = (std::string) " " + map[i];
    return puts(dfs(1, 1) ? (dfs(1, 1) ? "2" : "1") : "0"), 0;
}