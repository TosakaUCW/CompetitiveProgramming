#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <math.h>

const int N = 2e3 + 5;

int k;
int n, m;
int f[N][N];
std::string a, b;

int main()
{
    memset(f, 127, sizeof f);
    std::cin >> a >> b >> k;
    n = a.size(), m = b.size();
    for (int i = 0; i <= n; i++)
        f[i][0] = i * k;
    for (int j = 0; j <= m; j++)
        f[0][j] = j * k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = std::min(f[i][j], f[i - 1][j] + k);
            f[i][j] = std::min(f[i][j], f[i][j - 1] + k);
            f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]));
        }
    printf("%d", f[n][m]);
    return 0;
}