#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

int n, ans;
std::string str;
std::map<std::string, bool> map;

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> str, std::sort(str.begin(), str.end());
        if (!map[str])
            map[str] = true, ans++;
    }
    printf("%d", ans);
    return 0;
}