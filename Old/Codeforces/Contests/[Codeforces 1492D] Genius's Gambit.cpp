#include <stdio.h>
#include <string>
#include <iostream>

using std::string;

int a, b, k, x, y;

int main()
{
    std::cin >> a >> b >> k;
    if (!k)
        std::cout << "Yes\n"
                  << string(b, '1') + string(a, '0') << '\n'
                  << string(b, '1') + string(a, '0');
    else if (!a or b < 2 or a + b - 2 < k)
        puts("No");
    else
    {
        puts("Yes");
        int x = a + b - k - 2, y = std::min(b - 2, x);
        std::cout << 1 << string(y, '1') << string(x - y, '0') << 1 << string(b - 2 - y, '1') << string(a - 1 - x + y, '0') << 0 << '\n'
                  << 1 << string(y, '1') << string(x - y, '0') << 0 << string(b - 2 - y, '1') << string(a - 1 - x + y, '0') << 1;
    }
    return 0;
}