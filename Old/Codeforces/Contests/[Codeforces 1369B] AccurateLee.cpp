#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        std::string s;
        std::cin >> n >> s;
        int l = n - 1, r = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                l = i - 1;
                break;
            }
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '0')
            {
                r = i + 1;
                break;
            }
        for (int i = 0; i <= l; i++)
            printf("0");
        if (l + 1 < r)
            printf("0");
        for (int i = r; i < n; i++)
            printf("1");
        puts("");
    }
    return 0;
}