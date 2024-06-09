#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <unordered_map>
#include <iostream>

int k, ans, n;
std::string s, t;
std::unordered_map<std::string, int> map;

int main()
{
    std::cin >> s >> k, n = s.size();
    for (int i = 0; i + k - 1 < n; i++)
        t = s.substr(i, k), ans = std::max(ans, ++map[t]);
    printf("%d", ans);
    return 0;
}
