#include <stdio.h>
#include <algorithm>
#include <memory.h>

using std::max;
using std::min;

const int N = 5e3 + 5;

int n, k, a[N];
int f[N][N][2][2];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    n = read(), k = (n + 1) / 2;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    memset(f, 0x3f, sizeof f);
    f[0][0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
        {
            f[i][j][0][0] = min(f[i - 1][j][0][0], f[i - 1][j][1][0]);
            if (j)
            {
                f[i][j][0][1] = f[i - 1][j - 1][0][0] + max(0, a[i - 1] - (a[i] - 1)) + max(0, a[i + 1] - (a[i] - 1));
                if (i > 2)
                    f[i][j][0][1] = min(f[i][j][0][1], f[i - 1][j - 1][1][0] + max(0, a[i - 1] - (min(a[i], a[i - 2]) - 1)) - max(0, a[i - 1] - (a[i - 2] - 1)) + max(0, a[i + 1] - (a[i] - 1)));
            }
            f[i][j][1][0] = f[i - 1][j][0][1];
        }
    for (int j = 1; j <= k; j++)
        printf("%d ", std::min(f[n][j][0][0], std::min(f[n][j][1][0], f[n][j][0][1])));
    return 0;
}