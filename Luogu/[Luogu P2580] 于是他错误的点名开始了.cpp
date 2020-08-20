#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <string>
#include <iostream>

const int N = 1e5 + 5;

int n;
std::map<std::string, int> map;
std::string str;

int main()
{
    std::cin >> n;
    while (n--)
        std::cin >> str, map[str]++;
    std::cin >> n;
    while (n--)
    {
        std::cin >> str;
        if (map[str] == 0)
            puts("WRONG");
        else if (map[str] == 1)
            puts("OK"), map[str]++;
        else
            puts("REPEAT");
    }
    return 0;
}