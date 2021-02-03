#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

std::string a, b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    for (int T = read(); T--; puts(""))
    {
        std::cin >> a >> b;
        int an = a.size(), bn = b.size();
        int gcd = std::__gcd(an, bn);
        int lcm = an * bn / gcd;
        bool flag = true;
        for (int i = 1; i <= lcm; i++)
        {
            int p = i % an == 0 ? an : i % an;
            int q = i % bn == 0 ? bn : i % bn;
            if (a[p - 1] != b[q - 1])
                flag = false;
        }
        if (flag)
            for (int i = 1; i <= lcm / an; i++)
                std::cout << a;
        else
            printf("-1");
    }
    return 0;
}