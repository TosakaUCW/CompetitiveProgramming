#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

std::string str;

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
    std::cin >> str;
    std::cout << str;
    int len = str.size();
    for (int i = len - 1; i >= 0; i--)
        std::cout << str[i];
    return 0;
}