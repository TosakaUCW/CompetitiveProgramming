#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

const int N = 2e3 + 5;

int n, m;
std::string a, b;
int f[N][N];

int main()
{
    memset(f, 127, sizeof f);
    std::cin >> a >> b;
    n = a.size(), m = b.size();
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int j = 0; j <= m; j++)
        f[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
            {
                f[i][j] = std::min(f[i][j], f[i - 1][j] + 1);
                f[i][j] = std::min(f[i][j], f[i][j - 1] + 1);
                f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + 1);
            }
    printf("%d", f[n][m]);
    return 0;
}