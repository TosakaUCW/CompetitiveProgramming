#include <algorithm>
#include <iostream>
#include <string>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int len;
std::string a, b;

int main()
{
    std::cin >> a;
    b = a;
    len = a.length();
    std::reverse(a.begin(), a.end());
    Rep(i, 0, len)
    {
        if (a[i] == 'b')
            a[i] = 'd';
        else if (a[i] == 'd')
            a[i] = 'b';
        else if (a[i] == 'p')
            a[i] = 'q';
        else if (a[i] == 'q')
            a[i] = 'p';
    }
    if (a == b)
        std::cout << "Yes";
    else
        std::cout << "No";
    return 0;
}