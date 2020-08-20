#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

const int N = 1e2 + 5;
const int d[6][6] =
    {
        {0, 0, 0, 0, 0, 0},
        {0, 5, -1, -2, -1, -3},
        {0, -1, 5, -3, -2, -4},
        {0, -2, -3, 5, -2, -2},
        {0, -1, -2, -2, 5, -1},
        {0, -3, -4, -2, -1, 0}};

int n, m;
int a[N], b[N];
int f[N][N];
std::string p, q;

int con(int i, char ch)
{
    if (ch == 'A')
        return 1;
    if (ch == 'C')
        return 2;
    if (ch == 'G')
        return 3;
    if (ch == 'T')
        return 4;
}

int main()
{
    memset(f, 0xcf, sizeof f);
    std::cin >> n >> p >> m >> q;
    for (int i = 0; i < n; i++)
        a[i + 1] = con(i, p[i]);
    for (int i = 0; i < m; i++)
        b[i + 1] = con(i, q[i]);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        f[i][0] = f[i - 1][0] + d[a[i]][5];
    for (int i = 1; i <= m; i++)
        f[0][i] = f[0][i - 1] + d[5][b[i]];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = std::max(f[i - 1][j - 1] + d[a[i]][b[j]], std::max(f[i - 1][j] + d[a[i]][5], f[i][j - 1] + d[5][b[j]]));
    printf("%d", f[n][m]);
    return 0;
}