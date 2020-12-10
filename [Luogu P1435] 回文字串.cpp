#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

const int N = 1e3 + 5;

int len, ans;
std::string a, b;
int f[N][N];

int main()
{
    std::cin >> a;
    len = a.size();
    for (int i = len - 1; i >= 0; i--)
        b += a[i];
    // std::cout << b;
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
    std::cout << len - f[len][len];
    return 0;
}