#include <stdio.h>
#include <iostream>
#include <string>

long long n, p, ans, num;
std::string s[50];

int main()
{
    scanf("%lld%lld", &n, &p);
    p /= 2;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    for (int i = n; i >= 1; i--)
    {
        num *= 2;
        if (s[i] == "halfplus")
            num++;
        ans += num;
    }
    printf("%lld", ans * p);
    return 0;
}