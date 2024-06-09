#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 4e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int a[N], fa[N][25], sum[N], cnt = 2;

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

signed main()
{
    a[1] = sum[1] = sum[2] = INF, fa[2][0] = 1;
    for (int q = read(), opt, x, y, last = 0; q--;)
    {
        opt = read(), x = (read() ^ last) + 1, y = read() ^ last;
        if (opt == 1)
        {
            if (a[x] >= y)
                fa[++cnt][0] = x, a[cnt] = y, sum[cnt] = sum[fa[cnt][0]] + y;
            else
            {
                for (int j = 20; j >= 0; j--)
                    if (fa[x][j] and a[fa[x][j]] < y)
                        x = fa[x][j];
                fa[++cnt][0] = fa[x][0], a[cnt] = y, sum[cnt] = sum[fa[cnt][0]] + y;
            }
            for (int j = 1; j <= 20; j++)
                fa[cnt][j] = fa[fa[cnt][j - 1]][j - 1];
        }
        else
        {
            int res = 0, xx = x;
            for (int j = 20; j >= 0; j--)
                if (fa[x][j] and sum[xx] - sum[fa[x][j]] <= y)
                    x = fa[x][j], res += 1LL << j;
            printf("%lld\n", res), last = res;
        }
    }
    return 0;
}