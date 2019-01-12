#include <stdio.h>
#include <iostream>
#include <string>

int n, l = 0, r = 1e9;
std::string a, b;

int main()
{
    scanf("%d", &n);
    printf("0 1\n");
    std::cin >> a;
    for (int i = 2; i <= n; i++)
    {
        int mid = (l + r) / 2;
        printf("%d 1\n", mid);
        std::cin >> b;
        if (a == b)
            l = mid;
        else
            r = mid;
    }
    printf("%d 0 %d 2", l, r);
    return 0;
}