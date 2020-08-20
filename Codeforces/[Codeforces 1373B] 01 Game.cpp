#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a[3];
        a[0] = a[1] = 0;
        std::string s;
        std::cin >> s;
        int len = s.size();
        for (int i = 0; i < len; i++)
            if (s[i] == '1')
                a[1]++;
            else
                a[0]++;
        a[0] = std::min(a[0], a[1]);
        if (a[0] % 2)
            puts("DA");
        else
            puts("NET");
    }
    return 0;
}