#include <stdio.h>
#include <iostream>
#include <string>

int ans, len;
std::string s;

int main()
{
    getline(std::cin, s);
    len = s.length() - 1;
    for (int i = 0; i <= len; i++)
        if (s[i] != ' ')
            ans++;
    printf("%d", ans);
    return 0;
}