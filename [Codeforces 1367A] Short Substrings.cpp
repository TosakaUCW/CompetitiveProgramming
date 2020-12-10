#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

int n, len1, len2;
std::string str, ans;

int main()
{
    std::cin >> n;
    while (n--)
    {
        str.clear();
        ans.clear();
        std::cin >> str;
        len1 = str.size();
        len2 = 0;
        for (int i = 0; i < len1; i += 2)
            if (ans[len2] != str[i])
                ans.push_back(str[i]), ans.push_back(str[i + 1]), len2 += 1;
            else
                ans.push_back(str[i + 1]), len2 += 1;
        std::cout << ans << '\n';
    }
    return 0;
}