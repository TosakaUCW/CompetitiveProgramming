#include <stdio.h>
#include <algorithm>
#include <memory.h>

using std::max;

const int N = 50 + 5;
const int T = 2.5e3 + 5;

int n, m, t, ans, f[N][N][T][3];
char map[N][N];

/*
0 - red
1 - blue
2 - none
*/

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
    freopen("draw.in", "r", stdin), freopen("draw.out", "w", stdout);
    n = read(), m = read(), t = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", map[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= t; k++)
                if (j == 1)
                {
                    f[i][j][k][0] = max(f[i - 1][m][k - 1][0], max(f[i - 1][m][k - 1][1], f[i - 1][m][k - 1][2]));
                    f[i][j][k][1] = max(f[i - 1][m][k - 1][0], max(f[i - 1][m][k - 1][1], f[i - 1][m][k - 1][2]));
                    f[i][j][k][2] = max(f[i - 1][m][k][0], max(f[i - 1][m][k][1], f[i - 1][m][k][2]));
                    f[i][j][k][map[i][j] - '0']++;
                }
                else
                {
                    f[i][j][k][0] = max(f[i][j - 1][k][0], max(f[i][j - 1][k - 1][1], f[i][j - 1][k - 1][2]));
                    f[i][j][k][1] = max(f[i][j - 1][k][1], max(f[i][j - 1][k - 1][0], f[i][j - 1][k - 1][2]));
                    f[i][j][k][2] = max(f[i][j - 1][k][2], max(f[i][j - 1][k][1], f[i][j - 1][k][0]));
                    f[i][j][k][map[i][j] - '0']++;
                }
    for (int k = 1; k <= t; k++)
        ans = max(ans, max(f[n][m][k][0], max(f[n][m][k][1], f[n][m][k][2])));
    return printf("%d", ans), 0;
}