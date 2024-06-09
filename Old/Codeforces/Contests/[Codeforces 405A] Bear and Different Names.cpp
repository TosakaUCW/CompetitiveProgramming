#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 50 + 5;

int n, k;
std::string str[N], opt;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        str[i] += ('A' + i / 26), str[i] += ('a' + (i - 1) % 26);
    for (int i = 1; i <= n - k + 1; i++)
    {
        std::cin >> opt;
        if (opt == "NO")
            str[i + k - 1] = str[i];
    }
    for (int i = 1; i <= n; i++)
        std::cout << str[i] << ' ';
    return 0;
}