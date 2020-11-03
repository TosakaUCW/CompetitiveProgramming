#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

int len;
std::string str;

void dfs(int x)
{
    if (x == len)
        return;
    if (str[x] == 'l')
        dfs(x + 1), printf("%d\n", x + 1);
    else
        printf("%d\n", x + 1), dfs(x + 1);
}

int main()
{
    std::cin >> str;
    return len = str.size(), dfs(0), 0;
}