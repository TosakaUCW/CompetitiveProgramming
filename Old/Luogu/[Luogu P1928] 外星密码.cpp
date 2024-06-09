#include <stdio.h>
#include <string>
#include <iostream>

std::string go()
{
    std::string res;
    res.clear();
    char ch;
    while (std::cin >> ch)
    {
        if (ch == '[')
        {
            int k;
            std::cin >> k;
            std::string tmp = go();
            while (k--)
                res += tmp;
        }
        else if (ch == ']')
            return res;
        else
            res += ch;
    }
}

int main()
{
    std::cout << go();
    return 0;
}