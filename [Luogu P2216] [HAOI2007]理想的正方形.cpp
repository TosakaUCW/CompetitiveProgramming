#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>

typedef long long ll;

const int N = 1e3 + 5;
const int INF = 2147483647;

int n, m, k, ans = INF;
int a[N][N], st_max[N][N][11], st_min[N][N][11];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

inline int query(int x, int y)
{
    int x1 = x + k - 1, y1 = y + k - 1;
    int s = log2(k);
    int max = std::max(st_max[x][y][s], std::max(st_max[x1 - (1 << s) + 1][y1 - (1 << s) + 1][s], std::max(st_max[x1 - (1 << s) + 1][y][s], st_max[x][y1 - (1 << s) + 1][s])));
    int min = std::min(st_min[x][y][s], std::min(st_min[x1 - (1 << s) + 1][y1 - (1 << s) + 1][s], std::min(st_min[x1 - (1 << s) + 1][y][s], st_min[x][y1 - (1 << s) + 1][s])));
    return max - min;
}

signed main()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), st_max[i][j][0] = st_min[i][j][0] = a[i][j];
    for (int k = 1; k <= log2(n); k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            for (int j = 1; j + (1 << k) - 1 <= m; j++)
            {
                st_min[i][j][k] = std::min(st_min[i][j][k - 1], std::min(st_min[i][j + (1 << (k - 1))][k - 1], std::min(st_min[i + (1 << (k - 1))][j][k - 1], st_min[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1])));
                st_max[i][j][k] = std::max(st_max[i][j][k - 1], std::max(st_max[i][j + (1 << (k - 1))][k - 1], std::max(st_max[i + (1 << (k - 1))][j][k - 1], st_max[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1])));
            }
    for (int i = 1; i + k - 1 <= n; i++)
        for (int j = 1; j + k - 1 <= m; j++)
            ans = std::min(ans, query(i, j));
    printf("%d", ans);
    return 0;
}