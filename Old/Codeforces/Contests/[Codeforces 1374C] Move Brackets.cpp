#include <stdio.h>
#include <iostream>

int n;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            char c;
            std::cin >> c;
            if (c == '(')
                cnt++;
            else if (cnt > 0)
                cnt--;
        }
        printf("%d\n", cnt);
    }
    return 0;
}