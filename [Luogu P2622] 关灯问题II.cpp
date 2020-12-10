#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 10 + 1;
const int M = 100 + 1;

int n, m;
int a[M][N], f[1 << 10];

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
    memset(f, 0x7f, sizeof f);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    f[(1 << n) - 1] = 0;
    for (int sta = (1 << n) - 1; ~sta; sta--)
        for (int j = 1; j <= m; j++)
        {
            int now = sta;
            for (int k = 1; k <= n; k++)
            {
                int tmp = 1 << (k - 1);
                if (a[j][k] == 0)
                    continue;
                else if (a[j][k] == 1 and (now & tmp))
                    now = now ^ tmp;
                else if (a[j][k] == -1 and !(now & tmp))
                    now = now ^ tmp;
            }
            f[now] = std::min(f[now], f[sta] + 1);
        }
    printf("%d", f[0] == 0x7f7f7f7f ? -1 : f[0]);
    return 0;
}