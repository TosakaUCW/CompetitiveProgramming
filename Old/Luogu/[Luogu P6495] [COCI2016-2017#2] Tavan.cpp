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

const int N = 5e2 + 5;
const int M = 5e2 + 5;
const int K = 26 + 5;
const int X = 1e9 + 5;

int n, m, k, x;
std::string str[N];

int main()
{
    n = read(), m = read(), k = read(), x = read();
    for (int i = 0; i <= m; i++)
    {
        std::cin >> str[i];
        if (i)
            std::sort(str[i].begin(), str[i].end());
    }
    for (int i = n - 1; i >= 0; i--)
        if (str[0][i] == '#')
            str[0][i] = str[m][(x % k == 0 ? k : x % k) - 1],
            m--, x = x / k + (x % k != 0);
    std::cout << str[0];
    return 0;
}