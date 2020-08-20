#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

int s, t, len;
std::string str;

int main()
{
    std::cin >> s >> t >> len >> str;
    for (int T = 1; T <= 5; T++)
        for (int i = len - 1; i >= 0; i--)
            if (str[i] - 'a' + 1 <= i - len + t)
            {
                str[i]++;
                for (int j = i + 1; j < len; j++)
                    str[j] = str[j - 1] + 1;
                std::cout << str << '\n';
                break;
            }
    return 0;
}
/*
2 10 5
bdfij
*/